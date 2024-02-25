//
// Created by igriega on 24/02/24.
//

#include <random>
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

void StackHanoi::initWithRandoms(int min, int max, int totalElements) {
    if( (max-min) < totalElements){
        throw std::invalid_argument("Error: No se pueden generar los suficientes numeros random");
    }
    std::random_device rd; // Obtener una semilla aleatoria del dispositivo
    std::mt19937 gen(rd()); // Inicializar un generador de números aleatorios con la semilla
    std::uniform_int_distribution<int> dist(min, max); // Crea una distribución uniforme de enteros
    int randomNumber;
    for (int i = 0; i < totalElements; ++i) {
        bool ingresar = true;
        randomNumber = dist(gen);
        Node<int>* current;
        for (int j = 0; j < this->getSize(); ++j) {
            if(j==0){
                current = this->peek();
            }else{
                current = current->getNext();
            }

            if(current->getContent() == randomNumber){
                i--;
                ingresar = false;
                break;
            }

        }
        if(ingresar){
            this->push(randomNumber);
        }
    }
}
