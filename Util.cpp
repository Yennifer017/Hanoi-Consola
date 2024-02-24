//
// Created by igriega on 24/02/24.
//

#include <string>
#include <iostream>
#include <ctime>
#include <set>
#include <random>
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

int* Util::getNonRepeatsNumbers(int min, int max, int totalNumbers) {
    /*int* numbers[totalNumbers];
    std::random_device rd; // semilla aleatoria del dispositivo
    std::mt19937 gen(rd()); // Inicializar un generador de números aleatorios

    std::uniform_int_distribution<int> dist(min, max); // Crea una distribución uniforme de enteros
    for (int i = 0; i < totalNumbers; ++i) {
        int randomNumber = dist(gen); // Genera un número aleatorio
        bool repetido = false;
        for (int j = 0; j < i; ++j) {
            if(*numbers[j] == randomNumber){
                repetido = true;
                i--;
                break;
            }
        }
        if(!repetido){
            numbers[i] = &randomNumber;
        }
    }
    return *numbers;*/
    int numbersRandom[7] = {1,9,7,20,4,6,3};
    return numbersRandom;
}

void Util::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        // ANSI Escape Code for clearing the screen
        std::cout << "\033[2J\033[1;1H";

    #endif

}

void Util::enterContinuar() {
    std::cout<<"Ingrese cualquier letra/numero para continuar\n";
    std::string lectura;
    std::cin >> lectura;
    lectura.clear();
}

