//
// Created by simabogdan on 5/10/23.
//

#include <iostream>
#include "VendingMachine.h"
#include "entity.h"
#include "repo.h"
#include "service.h"

using namespace std;

VendingMachine::VendingMachine(){
    this->unBan = 0;
    this->cinciBani = 0;
    this->zeceBani = 0;
    this->cincizeciBani = 0;
    this->bani = 0;
}
VendingMachine::~VendingMachine(){}

void VendingMachine::addMoney(VendingMachine &machine, int moneda){
    if(moneda == 1){
        this->monezi.push_back(moneda);
        this->unBan++;
    }
    if(moneda == 5){
        this->monezi.push_back(moneda);
        this->cinciBani++;
    }
    if(moneda == 10){
        this->monezi.push_back(moneda);
        this->zeceBani++;
    }
    if(moneda == 50){
        this->monezi.push_back(moneda);
        this->cincizeciBani++;
    }
}

void VendingMachine::delMoney(VendingMachine& machine, int moneda){
    int suma = 0;
//    for(int i = 0; i < getSize(); i++){
//        if(suma < moneda && moneda < 5 && getMoney()[i] == 1){
//            suma++;
//            this->monezi.erase(this->monezi.begin() + i);
//        }
//        if(suma < moneda && (moneda >= 5 && moneda < 10) && getMoney()[i] == 5){
//            suma+=5;
//            this->monezi.erase(this->monezi.begin() + i);
//        }
//        if(suma <= moneda && (moneda >= 10 && moneda < 50) && getMoney()[i] == 10){
//            suma+=10;
//            this->monezi.erase(this->monezi.begin() + i);
//        }
//        if(suma <= moneda && moneda >= 50 && getMoney()[i] == 50){
//            suma+=50;
//            this->monezi.erase(this->monezi.begin() + i);
//        }
//    }

//    for(int i = 0; i < getSize(); i++){
//        if(suma <= moneda && moneda < 5 && getMoney()[i] == 1){
//            suma++;
//            this->monezi.erase(this->monezi.begin() + i);
//            i = 0;
//        }
//        if(suma <= moneda && (moneda >= 5 && moneda < 10) && getMoney()[i] == 5){
//            suma+=5;
//            this->monezi.erase(this->monezi.begin() + i);
//            i = 0;
//        }
//        if(suma <= moneda && (moneda >= 10 && moneda < 50) && getMoney()[i] == 10){
//            suma+=10;
//            this->monezi.erase(this->monezi.begin() + i);
//            i = 0;
//        }
//        if(suma <= moneda && moneda >= 50 && getMoney()[i] == 50){
//            suma+=50;
//            this->monezi.erase(this->monezi.begin() + i);
//            i = 0;
//        }
//    }

    while(moneda > 0){
        for(int i = 0; i < getSize(); i++){
            if(moneda < 5 && getMoney()[i] == 1){
                moneda--;
                this->monezi.erase(this->monezi.begin() + i);
            }
            if(moneda >= 5 && moneda < 10 && getMoney()[i] == 5){
                moneda = moneda - 5;
                this->monezi.erase(this->monezi.begin() + i);
            }
            if(moneda >= 10 && moneda < 50 && getMoney()[i] == 10){
                moneda-=10;
                this->monezi.erase(this->monezi.begin() + i);
            }
            if(moneda >= 50 && getMoney()[i] == 50){
                moneda-=50;
                this->monezi.erase(this->monezi.begin() + i);
            }
        }
    }
}

void VendingMachine::alimentare(VendingMachine &machine){
    for(int i = 0; i < 25; i++){
        if(i < 5){
            machine.addMoney(machine, 1);
        }
        if(i > 5 && i < 10){
            machine.addMoney(machine, 5);
        }
        if(i > 10 && i < 15){
            machine.addMoney(machine, 10);
        }
        if(i > 15 && i < 20){
            machine.addMoney(machine, 50);
        }
    }
}

std::vector<int>& VendingMachine::getMoney(){
    return this->monezi;
}

int VendingMachine::getUnBan(){
    return this->unBan;
}

int VendingMachine::getCinciBani() {
    return this->cinciBani;
}

int VendingMachine::getZeceBani() {
   return this->zeceBani;
}

int VendingMachine::getCinciZeciBani() {
    return this->cincizeciBani;
}

int VendingMachine::getBani(){
    return this->bani;
}

int VendingMachine::getSize(){
    return this->monezi.size();
}

