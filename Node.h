//
// Created by igriega on 24/02/24.
//

#ifndef HANOI_NODE_H
#define HANOI_NODE_H

template <class T>
class Node {
private:
    T content;
    Node<T> *next;
public:
    //constructores
    Node(T content){
        this->content = content;
        this->next = nullptr;
    };
    Node(T content, Node<T>* next){
        this->content = content;
        this->next = next;
    };

    /* METODOS */
    void emptyReferences(){
        this->next = nullptr;
    }

    //GETTERS
    T getContent(){
        return this->content;
    };
    Node<T>* getNext(){
        return this->next;
    };
    //SETTERS
    void setContent(T _content){
        this->content = _content;
    }
    void setNext(Node<T>* _next){
        this->next = _next;
    }
};


#endif //HANOI_NODE_H
