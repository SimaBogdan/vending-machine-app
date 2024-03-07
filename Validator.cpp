//
// Created by simabogdan on 5/24/23.
//
#include <iostream>
#include "Validator.h"

using namespace std;

int Validator::validare(Entity &entity1) {
    if (entity1.getCode() < 0 || entity1.getPrice() < 0){
        throw std::invalid_argument("Entitatea nu este ok!");
    }
    return 0;
}