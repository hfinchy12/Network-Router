#ifndef QUEUE_H
#define QUEUE_H
#include <sstream>
#include <iostream>
#include "DoublyLinkedList.h"
#include "NetworkPacket.h"


template <typename T>
class Queue {
    private:
        DoublyLinkedList<T> queueList;
    public: 
        // empty() returns a boolean indicating if the queue is empty or not.
        // push_back(NetworkPacket data) inserts a new packet at the end of the queue.
        // pop_front() removes the front element from the queue and returns its value.
        // toString() is used for autograding and should behave like the toString() method implemented in the DoublyLinkedLis
        
        Queue(){}

        bool empty(){
            if(queueList.getLength() == 0){
                return true;
            } else {
                return false;
            }
        }

        void push_back(T data){
            queueList.insert(data, queueList.getLength());
        }

        T pop_front(){
            T packet;
            Node<T>* returnMe = queueList.getFront();
            packet = returnMe->data;
            queueList.remove(0);
            return packet;
        }

        std::string toString(){
            return queueList.toString();
        }
};
#endif