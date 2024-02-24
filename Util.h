//
// Created by igriega on 24/02/24.
//

#ifndef HANOI_UTIL_H
#define HANOI_UTIL_H


class Util {
public:
    int getNumber();
    int getNaturalNumber(int min, int max);
    int* getNonRepeatsNumbers(int min, int max, int totalNumbers);
    void clearConsole();
    void enterContinuar();
};


#endif //HANOI_UTIL_H
