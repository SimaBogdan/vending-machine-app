//
// Created by simabogdan on 5/3/23.
//

#include "entity.h"
#include <iostream>
#include <cstring>

using namespace std;

Entity::Entity()
{
    this->code = 0;
    this->price = 0;
    this->name = "";
}

Entity::Entity(const Entity& e)
{
    this->code = e.code;
    this->price = e.price;
    this->name = e.name;
}

Entity::Entity(int code, const std::string name, double price)
{
    this->code = code;
    this->price = price;
    this->name = name;
}

int Entity::getCode()
{
    return this->code;
}

double Entity::getPrice()
{
    return this->price;
}

const std::string Entity::getName()
{
    return this->name;
}

void Entity::setCode(int code)
{
    this->code = code;
}

void Entity::setPrice(double price)
{
    this->price = price;
}

void Entity::setName(const std::string name)
{
    this->name = name;
}

Entity& Entity::operator=(const Entity& e)
{
    this->code = e.code;
    this->price = e.price;
    this->name = e.name;
    return *this;
}

bool Entity::operator==(const Entity& e)
{
    return this->code == e.code && this->price == e.price && this->name == name;
}

std::ostream& operator<<(std::ostream& os, const Entity& e)
{
    return os << "Name: " << e.name << " / Price: " << e.price << " / Code: " << e.code << "\n";
}