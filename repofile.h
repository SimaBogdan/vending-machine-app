//
// Created by simabogdan on 5/15/23.
//

#ifndef LAB9_10OOP_REPOFILE_H
#define LAB9_10OOP_REPOFILE_H
#include <iostream>
#include "fstream"
#include <cstring>
#include "repo.h"
#include "entity.h"

using namespace std;

class RepoFile: private Repo{
private:
    string filename;
public:
    //constructor
    RepoFile():Repo(){}

    //deconstructor
    ~RepoFile(){}

    //save the file
    void save();

    //load the file
    void load();

    //adds entities
    void addElem(Entity& entity);

    //getter pentru elemente
    Entity getElem(int i);

    //modifica entitatiile dupa cod
    void modifyFile(Entity& nou, int code);

    //getter pentru nr de elemente
    int getSizeFile();

    //getter pentru toate elementele
    std::vector<Entity>& getAllFile();

    //sterge elemente
    void delFile(Entity& entity);

};


#endif //LAB9_10OOP_REPOFILE_H
