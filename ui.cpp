//
// Created by simabogdan on 5/8/23.
//

#include "VendingMachine.h"
#include "ui.h"
#include "service.h"
#include "repo.h"
#include "entity.h"
#include <iostream>
#include "UIException.h"

using namespace std;

UI::UI(Service &service) : service(service) {}
UI::~UI() {}

void UI::menu() {
    bool rulare = true;
    RepoFile repo;
    Service service(repo);
    VendingMachine machine;
    machine.alimentare(machine);

    while (rulare) {
        cout << "1. Adauga \n"
             << "2. Listeaza \n"
             << "3. Modifica \n"
             << "4. Sterge \n"
             << "5. Afiseaza Monezi \n"
             << "6. Load File \n"
             << "7. Tranzactie \n"
             << "0. Exit \n";

        int optiune;
        cout << "Comanda: ";
        cin >> optiune;
        cout << "\n";

        try {
            switch (optiune) {
                case 0: {
                    rulare = false;
                    break;
                }
                case 1: {
                    try {
                        int cod;
                        double price;
                        std::string name;
                        cout << "Cod: ";
                        cin >> cod;
                        cout << "\nNume: ";
                        cin.get();
                        std::getline(std::cin, name);
                        cout << "\nPret: ";
                        cin >> price;
                        cout << "\n";
                        Entity entity(cod, name, price);
                        service.add(entity);
                    } catch (const std::invalid_argument& e) {
                        cout << "Elementele introduse nu sunt convenabile, codul trebuie sa fie un numar pozitiv, asemena si pretul" << endl;
                    }
                    break;
                }
                case 2: {
                    try {
                        cout << "Elementele sunt: \n";
                        Entity entity;
                        for (int i = 0; i < service.getSize(); i++) {
                            cout << "Cod: " << service.getAll()[i].getCode() << " Nume: " << service.getAll()[i].getName()
                                 << " Pret: " << service.getAll()[i].getPrice() << '\n';
                        }
                    } catch (const std::exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                }
                case 3: {
                    try {
                        int cod, codNou;
                        double priceNou;
                        std::string nameNou;
                        cout << "Ce element doriti sa modificati: ";
                        cin >> cod;
                        cout << "\nCod nou: ";
                        cin >> codNou;
                        cout << "\nNume nou: ";
                        cin.get();
                        std::getline(std::cin, nameNou);
                        cout << "\nPret nou: ";
                        cin >> priceNou;
                        Entity nou(codNou, nameNou, priceNou);
                        service.modify(nou, cod);
                    } catch (const std::invalid_argument& e) {
                        cout << "Elementele introduse nu sunt convenabile, codul trebuie sa fie un numar pozitiv, asemena si pretul" << endl;
                    }
                    break;
                }
                case 4: {
                    try {
                        int cod;
                        std::string name;
                        double price;
                        cout << "Cod de sters: ";
                        cin >> cod;
                        cout << "\nNume de sters: ";
                        cin.get();
                        std::getline(std::cin, name);
                        cout << "\nPret de sters: ";
                        cin >> price;
                        Entity entity(cod, name, price);
                        service.del(entity);
                    } catch (const std::invalid_argument& e) {
                        cout << "Elementele introduse nu sunt convenabile, codul trebuie sa fie un numar pozitiv, asemena si pretul" << endl;
                    }
                    break;
                }
                case 5: {
                    try {
                        int comanda;
                        cout << "Doriti sa afisati toate monedele sau unele anume?\n"
                             << "1. Toate\n"
                             << "2. Unele\n"
                             << "Comanda: ";
                        cin >> comanda;
                        cout << "\n";

                        if (comanda == 1) {
                            cout << "Numarul de monede totale: " << machine.getSize() << "\n";
                            cout << "Monezile: ";
                            for (int i = 0; i < machine.getSize(); i++) {
                                cout << machine.getMoney()[i] << " ";
                            }
                            cout << "\n";
                        } else if (comanda == 2) {
                            int moneda;
                            cout << "Ce fel de moneda(1, 5, 10, 50)\n";
                            cin >> moneda;

                            if (moneda == 1) {
                                cout << machine.getUnBan() << "\n";
                            }
                            if (moneda == 5) {
                                cout << machine.getCinciBani() << "\n";
                            }
                            if (moneda == 10) {
                                cout << machine.getZeceBani() << "\n";
                            }
                            if (moneda == 50) {
                                cout << machine.getCinciZeciBani() << "\n";
                            }
                        }
                    } catch (const std::exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                }
                case 6: {
                    try {
                        service.load();
                    } catch (const std::exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                }
                case 7: {
                    try {
                        cout << "Ce doriti sa cumparati? (dupa cod) \n";
                        Entity entity;
                        int code;
                        cin >> code;
                        cout << "Introduceti moneda: ";
                        int rest = 0, bani;
                        cin >> bani;
                        cout << "\n";
                        bool gasit = false;
                        service.tranzactie(entity, machine, code, bani, rest, gasit);
                        if (rest == 0) {
                            cout << "Tranzactie reusita" << "\n";
                        } else if (rest != 0 && gasit) {
                            cout << "Tranzactie reusita. Restul este: " << rest << "\n";
                        } else if (rest == -1) {
                            cout << "Bani insuficienti, va rugam introduceti o valoare suficienta\n";
                        }
                    } catch (const std::exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                }
                default:
                    throw UIException("Invalid option. Please choose a valid option.");
            }
        } catch (const UIException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}
