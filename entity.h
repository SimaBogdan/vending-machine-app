//
// Created by simabogdan on 5/3/23.
//

#ifndef LAB9_10OOP_ENTITY_H
#define LAB9_10OOP_ENTITY_H
#include <iostream>
#include <cstring>


class Entity {
private:
    int code;
    double price;
    std::string name;
public:
    Entity();
    Entity(const Entity& e);
    Entity(int code, const std::string name, double price);
    ~Entity() = default;

    // getters
    int getCode();
    double getPrice();
    const std::string getName();

    // setters
    void setCode(int code);
    void setPrice(double price);
    void setName(const std::string name);

    // operators
    Entity& operator=(const Entity& e);
    bool operator==(const Entity& e);
    friend std::ostream& operator<<(std::ostream& os, const Entity& e);
};


#endif //LAB9_10OOP_ENTITY_H
