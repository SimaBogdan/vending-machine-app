//
// Created by simabogdan on 5/3/23.
//

#include "repo.h"
#include <iostream>
#include <string.h>
#include <vector>

Repo::Repo()
{
    this->entities = std::vector<Entity>();
}

void Repo::add(Entity& e)
{
    this->entities.push_back(e);
}

void Repo::modify(Entity &nou, int code){
    for(int i = 0; i < this->entities.size(); i++){
        if(this->entities[i].getCode() != nou.getCode() && this->entities[i].getName() != nou.getName() && this->entities[i].getPrice() != nou.getPrice() && this->entities[i].getCode() == code){
            this->entities[i] = nou;
        }
    }
}

void Repo::del(Entity &entity){
    for(int i = 0; i < this->entities.size(); i++){
        if(this->entities[i].getCode() == entity.getCode() && this->entities[i].getName() == entity.getName() && this->entities[i].getPrice() == entity.getPrice()){
            this->entities.erase(this->entities.begin() + i);
        }
    }
}

std::vector<Entity>& Repo::getAll()
{
    return this->entities;
}

int Repo::getSize(){
    return this->entities.size();
}

void Repo::validator(Entity& e)
{
    std::string s = "";
    if (e.getPrice() <= 0)
        s += "Price cannot be negative or 0!\n";
}

void Repo::destroy() {
    this->entities = std::vector<Entity>();
}