#include <iostream>
#include "entity.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "VendingMachine.h"
#include "teste.h"

using namespace std;

void alimentare(VendingMachine &machine){
    for(int i = 0; i < 100; i++){
        if(i < 25){
            machine.addMoney(machine, 1);
        }
        if(i > 25 && i < 50){
            machine.addMoney(machine, 5);
        }
        if(i > 50 && i < 75){
            machine.addMoney(machine, 10);
        }
        if(i > 75 && i < 100){
            machine.addMoney(machine, 50);
        }
    }
}

int main() {
    tests();
    RepoFile repo;
    Service service(repo);
    VendingMachine machine;
    alimentare(machine);
//    for(int i = 0; i < machine.getSize(); i++){
//        cout << machine.getMoney()[i] << " ";
//    }
    UI ui(service);
    ui.menu();
    return 0;
}
