//
// Created by simabogdan on 5/22/23.
//

#ifndef LAB9_10OOP_UIEXCEPTION_H
#define LAB9_10OOP_UIEXCEPTION_H

#include <stdexcept>

class UIException : public std::exception {
public:
    explicit UIException(const std::string& message) : msg_(message) {}

    const char* what() const noexcept override {
        return msg_.c_str();
    }

private:
    std::string msg_;
};


#endif //LAB9_10OOP_UIEXCEPTION_H
