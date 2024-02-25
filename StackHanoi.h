//
// Created by igriega on 24/02/24.
//

#ifndef HANOI_STACKHANOI_H
#define HANOI_STACKHANOI_H

#include "Stack.h"

class StackHanoi: public Stack<int> {
public:
    std::string showElements();
    void pushConditional(Node<int>* &node);
    bool canPushConditional(int number);
    void initWithRandoms(int min, int max, int totalElements);
};


#endif //HANOI_STACKHANOI_H
