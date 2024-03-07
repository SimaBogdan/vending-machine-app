//
// Created by simabogdan on 5/3/23.
//

#include "entity.h"
#include "repo.h"
#include "repofile.h"
#include "service.h"
#include "VendingMachine.h"
#include "teste.h"
#include <assert.h>
#include <iostream>
#include <cstring>

using namespace std;

void testAdd()
{
    Repo repo;
    Entity e(12345, "suc", 25);
    repo.add(e);
    assert(repo.getAll().size() == 1);
    assert(repo.getAll()[0].getCode() == 12345);
    assert(repo.getAll()[0].getName() == "suc");
    assert(repo.getAll()[0].getPrice() == 25);
    repo.getAll()[0].setCode(67890);
    repo.getAll()[0].setName("ciocolata");
    repo.getAll()[0].setPrice(50);
    assert(repo.getAll()[0].getCode() == 67890);
    assert(repo.getAll()[0].getName() == "ciocolata");
    assert(repo.getAll()[0].getPrice() == 50);
}

void testAddService()
{
    RepoFile repoFile;
    Service service(repoFile);
    Entity e(12345, "suc", 25);
    service.add(e);
    assert(service.getAll().size() == 1);
    assert(service.getAll()[0].getCode() == 12345);
    assert(service.getAll()[0].getName() == "suc");
    assert(service.getAll()[0].getPrice() == 25);
    service.getAll()[0].setCode(67890);
    service.getAll()[0].setName("ciocolata");
    service.getAll()[0].setPrice(50);
    assert(service.getAll()[0].getCode() == 67890);
    assert(service.getAll()[0].getName() == "ciocolata");
    assert(service.getAll()[0].getPrice() == 50);
}

void testModify(){
    Repo repo;
    Entity e(12345, "suc", 25);
    Entity e1(678910, "ciocolata", 50);
    repo.add(e);
    repo.modify(e1, 12345);
    assert(repo.getAll().size() == 1);
    assert(repo.getAll()[0].getCode() == 678910);
    assert(repo.getAll()[0].getName() == "ciocolata");
    assert(repo.getAll()[0].getPrice() == 50);
}

void testModifyService(){
    RepoFile repo;
    Service service(repo);
    Entity e(12345, "suc", 25);
    Entity e1(678910, "ciocolata", 50);
    service.add(e);
    service.modify(e1, 12345);
    assert(service.getAll().size() == 1);
    assert(service.getAll()[0].getCode() == 678910);
    assert(service.getAll()[0].getName() == "ciocolata");
    assert(service.getAll()[0].getPrice() == 50);
}

void testDel(){
    Repo repo;
    Entity e(12345, "suc", 25);
    Entity e1(678910, "ciocolata", 50);
    repo.add(e);
    repo.add(e1);
    repo.del(e1);
    assert(repo.getAll().size() == 1);
}

void testDelService(){
    RepoFile repo;
    Service service(repo);
    Entity e(12345, "suc", 25);
    Entity e1(678910, "ciocolata", 50);
    service.add(e);
    service.add(e1);
    service.del(e1);
    assert(service.getAll().size() == 1);
}

void testAddMoney(){
    VendingMachine machine;
    machine.addMoney(machine, 1);
    machine.addMoney(machine, 5);
    machine.addMoney(machine, 10);
    machine.addMoney(machine, 50);
    assert(machine.getSize() == 4);
    assert(machine.getMoney()[0] == 1);
    assert(machine.getMoney()[1] == 5);
    assert(machine.getMoney()[2] == 10);
    assert(machine.getMoney()[3] == 50);
}

void testTranzactii(){
    RepoFile repoFile;
    Service service(repoFile);
    VendingMachine machine;
    int bani = 50, rest = 0, code = 1;
    bool gasit = true;
    Entity e0(1, "ciocolata", 50);
    Entity e1(2, "suc", 10);
    service.add(e0);
    service.add(e1);
    Entity entity;
    service.tranzactie(e0, machine, code, bani, rest, gasit);
    assert(rest == 0);
    assert(gasit == true);
    bani = 51;
    service.tranzactie(e0, machine, code, bani, rest, gasit);
    assert(rest == 1);
    assert(gasit == true);
}

void tests()
{
    testAdd();
    testModify();
    testDel();
    testAddService();
    testModifyService();
    testDelService();
    testAddMoney();
    //testTranzactii();

    std::cout << "Tests passed\n";
}