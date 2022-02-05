// TODO: Define the DoublyDoublyLinkedList class
#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

template <typename T>
class DoublyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
    int list_size;

public:
	// Default constructor
	DoublyLinkedList();

	// Destructor
	~DoublyLinkedList();

	// Copy constructor
	DoublyLinkedList(const DoublyLinkedList<T>& other);

	// Copy assignment
	DoublyLinkedList& operator=(const DoublyLinkedList<T>& other);

    // return length of linked list
    size_t getLength();

    // return head node of linked list
    Node<T>* getFront();

    //return tail node of linked list
    Node<T>* getBack();

	// Insert a record to the linked list
    void insert(T data, int index);

    // Delete a record from the linked list
    void remove(int index);

    // print out the entire linked list
    std::string toString();

	// Clear the content of this linked list
	void clear();


	// The functions below are written already. Do not modify them.
	std::string print() const;

	Node<T>* getHead() const { return head; }
};

// std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& ll);
#endif
