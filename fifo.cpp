/*********************
* Name: Ian Olsen
* Assignment: Challenge 2
* Date: 11/28/2022
* FIFO STACK
*********************/

#include "fifo.h"

////Singly Linked list that implements a queue using node and data struct.
////List will user a tail pointer and head pointer to keep track of the list.
////The list will be able to add and remove nodes from the list.
////The list will be able to print the list.
////The list will be able to check if the list is empty.
////The list will be able to peek at the next node to be removed.

//Constructor
Fifo::Fifo() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//Destructor
Fifo::~Fifo() {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

//Push data to TOP of the stack
bool Fifo::push(int id, string &information) {

    bool wasPushed;
    //Create a new node
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.information = information;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    //Check if stack is empty
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        size++;
        wasPushed = true;
    }

    //check if the stack is full
    else if (size == STACKSIZE) {
        wasPushed = false;
    }

    //Add node to stack
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
        wasPushed = true;
    }

    return wasPushed;
}

//Pull data from BOTTOM of the stack
bool Fifo::pull(Data &data) {

    bool wasPulled;
    //Check if stack is empty
    if (isEmpty()) {
        wasPulled = false;
    }

    //Pull data from stack
    else {
        data = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        wasPulled = true;
    }
    return wasPulled;
}

//peek at next node to be removed
bool Fifo::peek(Data &data) {

    bool wasPeeked;

    //Check if stack is empty
    if (isEmpty()) {
        wasPeeked = false;
    }

    //Peek at next node to be removed
    else {
        data = head->data;
        wasPeeked = true;
    }
    return wasPeeked;
}

//check if the list is empty
bool Fifo::isEmpty() {
    return head == nullptr;
}

//DEBUG DUMP contents of stack
void Fifo::dumpStack() {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data.id << ": " << temp->data.information << std::endl;
        temp = temp->next;
    }
    // if stack is empty print empty
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
    }
}