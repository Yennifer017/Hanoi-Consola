#include <iostream>

#include "Hanoi.h"
int main() {
    Util* util = new Util();
    do {
        Hanoi* hanoi = new Hanoi();
        hanoi->jugar();
        delete(hanoi);
        std::cout<<"Deseas jugar de nuevo? 0->No   1->Si"<<std::endl;
        int opcion = util->getNaturalNumber(0,1);
        if(opcion == 0){
            break;
        }
    } while (true);
    return 0;
}
