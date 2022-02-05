// TODO: Write the source functions for the DoublyDoublyLinkedList
#include <iostream>
#include <string>
#include <sstream>
#include "DoublyLinkedList.h"
#include "Node.h"
#include <cmath>

using std::cout;
using std::ostream;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(): head(nullptr), tail(nullptr), list_size(0){}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& source) {
    // Implement this function
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    // clear();
    Node<T>* curr = source.head;
    for(int i = 0; i < source.list_size; i++){
        this->insert(curr->getData(), i);
        curr = curr->getNext();
    }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& source) {
    // Implement this function
    clear();
    Node<T>* curr = source.head;

    for(int i = 0; i < source.list_size; i++){
        insert(curr->data, i);
        curr = curr->next;
    }
    
    return *this;
}

template <typename T>
size_t DoublyLinkedList<T>::getLength(){
    return list_size;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getFront(){
    return head;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getBack(){
    return tail;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, int index){
    if(index > list_size || index < 0){
        throw std::out_of_range("Index outside of list bounds");
    }
    //insert at front:
    if(list_size == 0){
        Node<T>* newNode = new Node<T>(data);
        head = newNode;
        tail = newNode;
    } else if(index == 0){
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (index == list_size){ // insert at end
        Node<T>* newNode = new Node<T>(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else{ // insert in middle
        Node<T>* newNode = new Node<T>(data);
        Node<T>* curr = head;
        int counter = 0;
        while(curr){
            if(counter == index){
                Node<T>* left = curr->prev;
                left->next = newNode;
                newNode->prev = left;
                newNode->next = curr;
                curr->prev = newNode;
                break;
            }
            counter++;
            curr = curr->next;
        }
    }
    list_size++;
}

template <typename T>
void DoublyLinkedList<T>::remove(int index){
    if(index >= list_size){
        throw std::out_of_range("Index outside of list bounds");
    }
    if(list_size == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
    }else if(index == 0){ // remove head
        Node<T>* temp = head->next;
        delete head;
        head = temp;
        head->prev = nullptr;
    }else if(index == list_size - 1){
        Node<T>* temp = tail->prev;
        tail->prev->next = nullptr;
        delete tail;
        tail = temp;
    }else{
        Node<T>* curr = head;
        int counter = 0;
        while(curr){
            if(counter == index){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                break;
            }else{
                curr = curr->next;
                counter++;
            }
        }
    }
    list_size--;
}

template <typename T>
std::string DoublyLinkedList<T>::toString(){
    Node<T>* curr = this->head;
    std::stringstream printMe;
    T d;
    while(curr){
        d = curr->data;
        printMe << d << " ";
        curr = curr->next;
    }
    return printMe.str();
}

template <typename T>
void DoublyLinkedList<T>::clear() {	
    // Implement this function
    Node<T>* temp = head;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<NetworkPacket>;
template class DoublyLinkedList<std::string>;