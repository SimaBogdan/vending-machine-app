//
// Created by simabogdan on 5/22/23.
//

#ifndef LAB9_10OOP_INVALIDMONEYVALUEEXCEPTION_H
#define LAB9_10OOP_INVALIDMONEYVALUEEXCEPTION_H

#include <stdexcept>

class InvalidMoneyValueException : public std::invalid_argument{
private:
    char* msg;
public:
    InvalidMoneyValueException(char* message) :
            std::invalid_argument(message), msg(message){

    }
    char* what(){
        return msg;
    }

};

#endif //LAB9_10OOP_INVALIDMONEYVALUEEXCEPTION_H
