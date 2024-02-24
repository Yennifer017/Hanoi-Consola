//
// Created by igriega on 24/02/24.
//

#ifndef HANOI_STACK_H
#define HANOI_STACK_H
#include <stdexcept>
#include "Node.h"
template <class T>

class Stack {

private:
    Node<T>* topElement;
    int size;
public:
    //constructores
    Stack() {
        topElement = nullptr;
        size = 0;
    };
    //metodos
    Node<T>* pop(){
        if(topElement!= nullptr){
            Node<T>* deletedNode = topElement;
            topElement = topElement->getNext();
            size--;
            return deletedNode;
        }else{
            throw std::out_of_range("Error: No se puede hacer eliminar en una lista vacía");
        }
    };
    Node<T>* peek(){
        return topElement;
    };
    void push(T content){
        Node<T>* newNode = new Node(content, topElement); //creando un nuevo nodo
        topElement = newNode;
        size++;
    };

    void push(Node<T>* &node){
        node->setNext(topElement);
        topElement =  node;
        size++;
    }
    bool isEmpty(){
        return size == 0;
    }
    int getSize(){
        return size;
    }
};


#endif //HANOI_STACK_H
