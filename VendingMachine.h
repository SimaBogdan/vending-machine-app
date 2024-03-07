//
// Created by simabogdan on 5/10/23.
//

#ifndef LAB9_10OOP_VENDINGMACHINE_H
#define LAB9_10OOP_VENDINGMACHINE_H
#include <vector>


class VendingMachine {
private:
    std::vector<int> monezi;
    int unBan, cinciBani, zeceBani, cincizeciBani, bani;
public:
    //constructor
    VendingMachine();

    //deconstructor
    ~VendingMachine();

    //adauga monezi
    void addMoney(VendingMachine &machine, int moneda);

    //alimenteaza dinainte tonomatul
    void alimentare(VendingMachine &machine);

    void delMoney(VendingMachine& machine, int moneda);

    //getter pentru monezi si marime
    std::vector<int>& getMoney();
    int getUnBan();
    int getCinciBani();
    int getZeceBani();
    int getCinciZeciBani();
    int getBani();
    int getSize();
};


#endif //LAB9_10OOP_VENDINGMACHINE_H
