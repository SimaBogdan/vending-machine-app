cmake_minimum_required(VERSION 3.25)
project(lab9_10OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9_10OOP main.cpp entity.cpp entity.h repo.cpp repo.h teste.cpp teste.h service.cpp service.h ui.cpp ui.h VendingMachine.cpp VendingMachine.h repofile.cpp repofile.h InvalidCodeException.h .idea/InvalidMoneyValueException.h .idea/NotFoundElementException.h .idea/ProductValidator.h .idea/MoneyValidator.h UIException.h Validator.h Validator.cpp)
