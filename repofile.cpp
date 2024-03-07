//
// Created by simabogdan on 5/15/23.
//

#include "repofile.h"
#include "repo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//ifstream f("date.txt");
//ofstream g("date.txt");

//int RepoFile::inInt(char v[100]) {
//    int nr = 0;
//    for(int i =  0; i < strlen(v); i++)
//        nr = nr*10 + int(v[i] - '0');
//    return nr;
//}
//
//void RepoFile::save() {
//    ofstream g("/home/simabogdan/Documents/lab9_10OOP/date.txt");
//    g << getSize() << endl;
//    for (int i = 0; i < getSize(); i++)
//    {
//        Entity produse = this->getElem(i);
//        g << Repo::getAll()[i].getCode() << " " << Repo::getAll()[i].getName() << " " << Repo::getAll()[i].getPrice() << endl;
//    }
//    g.close();
//}
//
//
//void RepoFile::load() {
//    ifstream f("..//repository/date.txt");
//    int n=getSize();
//    char s[100], v[7][100];
//    f>>n;
//    f.get();
//    Repo::destroy();
//    for(int i = 0;i < n;i++) {
//        f.getline(s, 100);
//        int nr = 0;
//        char* p = strtok(s, " ");
//        while(p != NULL)
//        {
//            strcpy(v[nr++],p);
//            p = strtok(NULL, " ");
//        }
//
//        Entity entity(inInt((v[1])), v[0], inInt(v[2]));
//        Repo::add(entity);
//        //Entity produse = Entity(inInt(v[1]), inInt(v[2]), v[0]);
//        //Repo::add(produse);
//    }
//    f.close();
//}

//void RepoFile::loadFile(){
//    //Repo repo;
//    ifstream f("date.txt");
//    int nr = 0;
//    if(f.is_open()){
//        int code;
//        string name;
//        double price;
//        while(!f.eof()){
////            code = repo.getAll()[nr].getCode();
////            name = repo.getAll()[nr].getName();
////            price = repo.getAll()[nr].getPrice();
//            f >> code >> name >> price;
//            Entity entity(code, name, price);
//            //Repo::add(entity);
//            nr++;
//        }
//    }
//    f.close();
//}
//
//void RepoFile::saveFile(){
//    //Repo repo;
//    ofstream g("date.txt");
//    std::vector<Entity>& repository = Repo::getAll();
//    g << Repo::getSize() << endl;
//    for (int i = 0; i < Repo::getSize(); i++)
//    {
//        g << Repo::getAll()[i].getCode() << " " << Repo::getAll()[i].getName() << " " << Repo::getAll()[i].getPrice() << endl;
//        Entity(Repo::getAll()[i].getCode(), Repo::getAll()[i].getName(), Repo::getAll()[i].getPrice());
//    }
//    g.close();
//}

void RepoFile::save() {
    ofstream file("/home/simabogdan/Documents/lab9_10OOP/date.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Error message");
    }
    if(file.is_open()){
        for(int i = 0; i < Repo::getSize(); i++){
            file << Repo::getAll()[i].getCode() << " " << Repo::getAll()[i].getName() << " " << Repo::getAll()[i].getPrice() << "\n";
            Entity(Repo::getAll()[i].getCode(), Repo::getAll()[i].getName(), Repo::getAll()[i].getPrice());
        }
        file.close();
    }
}

void RepoFile::load() {
    ifstream file("/home/simabogdan/Documents/lab9_10OOP/date.txt");
    int code;
    string name;
    double price;

    if (!file.is_open()) {
        throw std::runtime_error("Error message");
    }

    if(file.is_open()){
        while(file >> code >> name >> price){
            Entity entity(code, name, price);
            cout << code << " " << name << " " << price << "\n";
        }
        file.close();
    }
}

void RepoFile::addElem(Entity& entity){
    load();
    Repo::add(entity);
    save();
}

Entity RepoFile::getElem(int i){
   // Repo repo;
    return Repo::getAll()[i];
}

void RepoFile::modifyFile(Entity& nou, int code){
    load();
    //Repo repo;
    Repo::modify(nou, code);
    save();
}

int RepoFile::getSizeFile(){
    //Repo repo;
    return Repo::getSize();
}

std::vector<Entity>& RepoFile::getAllFile(){
    //Repo repo;
    return Repo::getAll();
}

void RepoFile::delFile(Entity &entity) {
    load();
    //Repo repo;
    Repo::del(entity);
    save();
}