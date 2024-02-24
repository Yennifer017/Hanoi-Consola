//
// Created by igriega on 24/02/24.
//

#include "StackHanoi.h"

std::string StackHanoi::showElements() {
    std::string content;
    if(!this->isEmpty()){
        Node<int>* current = this->peek(); //last
        content += std::to_string(current->getContent()) + " ";
        while (current->getNext() != nullptr){
            current = current->getNext();
            content += std::to_string(current->getContent()) + " ";
        }
    }else{
        content = "__vacio__";
    }
    return  content;
}

void StackHanoi::pushConditional(Node<int> *&node) {
    if(!isEmpty() && this->peek()->getContent() < node->getContent()){
        throw std::invalid_argument("Error: No se puede ingresar este elemento aqui");
    }
    Stack::push(node);
}

bool StackHanoi::canPushConditional(int number) {
    return isEmpty() || this->peek()->getContent() > number;
}
