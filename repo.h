//
// Created by simabogdan on 5/3/23.
//

#ifndef LAB9_10OOP_REPO_H
#define LAB9_10OOP_REPO_H
#include <iostream>
#include <vector>
#include "entity.h"

using namespace std;

class Repo {
private:
    std::vector<Entity> entities;
public:
    Repo();
    ~Repo() = default;

    // add entity
    void add(Entity& e);

    //modify entity
    void modify(Entity &nou, int code);

    //delete entity
    void del(Entity &entity);

    // get all entities
    std::vector<Entity>& getAll();

    //get size
    int getSize();

    // validator
    void validator(Entity& e);

    //destroys entities
    void destroy();
};


#endif //LAB9_10OOP_REPO_H
