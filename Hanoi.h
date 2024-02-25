//
// Created by igriega on 24/02/24.
//

#ifndef HANOI_HANOI_H
#define HANOI_HANOI_H
#include "StackHanoi.h"
#include "Util.h"

class Hanoi {
public:
    const static int TOTAL_STACKS = 3;
    const static int TOTAL_ELEMENTS = 7;
    Hanoi();
    void jugar();
private:
    StackHanoi* stacks[TOTAL_STACKS]{};
    Util* util;
    void showStacks();
    bool checkWinner();
};


#endif //HANOI_HANOI_H
