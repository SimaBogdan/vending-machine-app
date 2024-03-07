//
// Created by simabogdan on 5/8/23.
//

#include "service.h"
#include "repo.h"
#include "entity.h"
#include "/home/simabogdan/Documents/lab9_10OOP/.idea/NotFoundElementException.h"
#include "/home/simabogdan/Documents/lab9_10OOP/InvalidCodeException.h"
#include "/home/simabogdan/Documents/lab9_10OOP/.idea/ProductValidator.h"
#include "Validator.h"
#include <iostream>

using namespace std;

Service::Service(RepoFile repofile){
    this->repoFile = repofile;
}

Service::~Service(){}

void Service::add(Entity &entity){
//    if (entity.getCode() < 0 || entity.getPrice() < 0){
//        throw ElementNotFoundException("Entity not found!");
//    }

//    Validator validator;
//    validator.validare(entity);

    validator.validare(entity);
    repoFile.addElem(entity);
}

void Service::modify(Entity &entity, int cod){
//    if (entity.getCode() < 0 || entity.getPrice() < 0){
//        throw ElementNotFoundException("Entity not found!");
//    }



    validator.validare(entity);
    bool codeExists = false;
    for (Entity e : repoFile.getAllFile()) {
        if (e.getCode() == cod) {
            codeExists = true;
            break;
        }
    }

    if (!codeExists){
        throw InvalidCodeException("Codul nu exista!");
    }

        repoFile.modifyFile(entity, cod);
}

std::vector<Entity>& Service::getAll(){
    return this->repoFile.getAllFile();
}

int Service::getSize(){
    return this->repoFile.getSizeFile();
}

void Service::del(Entity &entity){
//    if (entity.getCode() < 0 || entity.getPrice() < 0){
//        throw ElementNotFoundException("Entity not found!");
//    }
    validator.validare(entity);
    repoFile.delFile(entity);
}

void Service::load(){
    this->repoFile.load();
}

void Service::save(){
    this->repoFile.save();
}

void Service::tranzactie(Entity& entity, VendingMachine& vendingMachine, int code, int bani, int& rest, bool& gasit){
//    if (entity.getCode() < 0 || entity.getPrice() < 0){
//        throw ElementNotFoundException("Entity not found!");
//    }

    validator.validare(entity);
    bool codeExists = false;
    for (Entity e : repoFile.getAllFile()) {
        if (e.getCode() == code) {
            codeExists = true;
            break;
        }
    }

    if (!codeExists){
        throw InvalidCodeException("Codul nu exista!");
    }
    gasit = false;
    rest = 0;
    for(int i = 0; i < repoFile.getSizeFile(); i++){
        if(repoFile.getAllFile()[i].getCode() == code){
            if(repoFile.getAllFile()[i].getPrice() == bani){
                rest = 0;
                gasit = true;
                vendingMachine.addMoney(vendingMachine, bani);
            }
            else if(repoFile.getAllFile()[i].getPrice() < bani){
                rest = bani - repoFile.getAllFile()[i].getPrice();
                gasit = true;
                vendingMachine.addMoney(vendingMachine, repoFile.getAllFile()[i].getPrice());
                vendingMachine.delMoney(vendingMachine, rest);
            }
            else if(repoFile.getAllFile()[i].getPrice() > bani){
                rest = -1;
                gasit = false;
            }
        }
    }
}