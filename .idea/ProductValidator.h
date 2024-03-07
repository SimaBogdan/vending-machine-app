//
// Created by simabogdan on 5/22/23.
//

#ifndef LAB9_10OOP_PRODUCTVALIDATOR_H
#define LAB9_10OOP_PRODUCTVALIDATOR_H

#include "/home/simabogdan/Documents/lab9_10OOP/InvalidCodeException.h"

class ProductValidator{
private:
    int validCode;
public:
    ProductValidator(int code) : validCode(code){
    }

    void validate(int code){
        if (code < validCode)
            throw InvalidCodeException("The given code must be natural number");
    }
};

#endif //LAB9_10OOP_PRODUCTVALIDATOR_H
