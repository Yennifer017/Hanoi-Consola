//
// Created by igriega on 24/02/24.
//

#include <set>
#include <iostream>
#include <iomanip>
#include "Hanoi.h"
Hanoi::Hanoi() {
    util = new Util();
    for (int i = 0; i < TOTAL_STACKS; ++i) {
        this->stacks[i] = new StackHanoi();
    }
    stacks[0]->initWithRandoms(1, 20, TOTAL_ELEMENTS);
}


void Hanoi::jugar() {
    bool winner = false;
    while (!winner){
        showStacks();
        std::cout<<"Ingrese el numero de pila donde se extraera el elemento [0 para salir]: ";
        int numStack = util->getNaturalNumber(0, TOTAL_STACKS);
        numStack--;
        if(numStack == -1){
            break;
        }else if(!stacks[numStack]->isEmpty()){
            std::cout<<"Ingrese la nueva pila a mover el elemento: ";
            int numNewStack = util->getNaturalNumber(0, TOTAL_STACKS);
            numNewStack--;
            if(numStack == numNewStack){
                std::cout<<"No se puede mover el elemento a la misma pila"<<std::endl;
                util->enterContinuar();
            }else if(stacks[numNewStack]->canPushConditional(stacks[numStack]->peek()->getContent())){
                Node<int>* node = stacks[numStack]->pop();
                stacks[numNewStack]->pushConditional(node);
            }else{
                std::cout<<"No es posible realizar ese movimiento"<<std::endl;
                util->enterContinuar();
            }
        }else{
            std::cout<<"No hay elementos en esa pila"<<std::endl;
            util->enterContinuar();
        }
        util->clearConsole();
        winner = checkWinner();
    }
    if(winner){
        std::cout<<"Felicidades Has ganado :D"<<std::endl;
    }else{
        std::cout<<"Mas suerte para la proxima u_u"<<std::endl;
    }
    util->enterContinuar();
}

void Hanoi::showStacks() {
    std::cout<<"__________________________________________________________"<<std::endl;
    std::cout<<"|                        *H*A*N*O*I*                     |"<<std::endl;
    std::cout<<"__________________________________________________________"<<std::endl;
    int maxCharacters = 40 + 10;
    for (int i = 0; i < TOTAL_STACKS; ++i) {
        std::cout << std::setw(maxCharacters) << std::right << stacks[i]->showElements();
        std::cout<<" -- "<< (i+1) << std::endl;
    }
}

bool Hanoi::checkWinner() {
    return stacks[0]->isEmpty() && (stacks[1]->isEmpty() || stacks[2]->isEmpty());
}



