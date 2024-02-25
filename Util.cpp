//
// Created by igriega on 24/02/24.
//

#include <string>
#include <iostream>
#include "Util.h"

int Util::getNumber() {
    do{
        try {
            std::string lectura;
            std::cin >> lectura;
            int number = std::stoi(lectura);
            return number;
        }
        catch (std::invalid_argument const &e) {
            std::cout << "Numero invalido, intentalo otra vez: ";
        }
        catch (std::out_of_range const &e) {
            std::cout << "Integer overflow error, ingresa un numero mas pequeno: ";
        }
    } while (true);
}

int Util::getNaturalNumber(int min, int max) {
    do {
        int number = getNumber();
        if(number>=min && number<=max){
            return number;
        }else{
            printf("Numbero invalido, debe estar entre %d y %d", min, max);
        }
    } while (true);
}

void Util::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        // ANSI Escape Code for clearing the screen
        std::cout << "\033[2J\033[1;1H"<<std::endl;

    #endif

}

void Util::enterContinuar() {
    std::cout<<"Ingrese cualquier letra/numero para continuar\n";
    std::string lectura;
    std::cin >> lectura;
    lectura.clear();
}

