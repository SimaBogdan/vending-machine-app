//
// Created by simabogdan on 5/23/23.
//

#ifndef LAB9_10OOP_VALIDATOR_H
#define LAB9_10OOP_VALIDATOR_H
#include <iostream>
#include "entity.h"
#include "/home/simabogdan/Documents/lab9_10OOP/.idea/NotFoundElementException.h"
#include "/home/simabogdan/Documents/lab9_10OOP/InvalidCodeException.h"

using namespace std;

class Validator{
private:
    Entity entity;
    char* message;
public:
    Validator() = default;
    ~Validator() = default;

    int validare(Entity& entity1);

};

#endif //LAB9_10OOP_VALIDATOR_H
