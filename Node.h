#ifndef NODE_H
#define NODE_H
#include "NetworkPacket.h"

template <typename T>
class Node 
{
    public:
    T data;
    Node* next;
    Node* prev;

    // Default constructor
    Node(){} // remember to initialize next to nullptr
    Node(const T& d){
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    T getData(){
        return data;
    }
    Node* getNext(){
        return next;
    }
    Node* getPrev(){
        return prev;
    }
    void setData(const T& d){
        data = d;
    }
    void setNext(Node* n){
        next = n;
    }
    void setPrev(Node* p){
        prev = p;
    }
    
    virtual ~Node() {}

};

template class Node<int>;
template class Node<NetworkPacket>;
template class Node<std::string>;

#endif