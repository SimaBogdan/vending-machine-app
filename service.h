//
// Created by simabogdan on 5/8/23.
//

#ifndef LAB9_10OOP_SERVICE_H
#define LAB9_10OOP_SERVICE_H
#include "repo.h"
#include "repofile.h"
#include "VendingMachine.h"
#include "Validator.h"
#include <iostream>

using namespace std;


class Service {
private:
    RepoFile repoFile;
    VendingMachine monede;
    Validator validator;
public:
    //constructor
    Service(RepoFile repoFile);

    //deconstructor
    ~Service();

    //add entities
    void add(Entity &entity);

    //modify entities
    void modify(Entity &entity, int cod);

    //get all entities
    std::vector<Entity>& getAll();

    //get size
    int getSize();

    //delete entities
    void del(Entity &entity);

    //load the file
    void load();

    //saves the file
    void save();

    //face tranzactiile si daca e nevoie da rest
    void tranzactie(Entity& entity, VendingMachine& vendingMachine, int code, int bani, int& rest, bool& gasit);
};


#endif //LAB9_10OOP_SERVICE_H
