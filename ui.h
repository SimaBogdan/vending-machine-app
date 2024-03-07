//
// Created by simabogdan on 5/8/23.
//

#ifndef LAB9_10OOP_UI_H
#define LAB9_10OOP_UI_H
#include "service.h"
#include "repo.h"
#include "entity.h"
#include <iostream>

using namespace std;

class UI {
private:
    Service &service;
public:
    //constructor
    UI(Service &service);

    //deconstructor
    ~UI();

    //meniu
    void menu();
};


#endif //LAB9_10OOP_UI_H
