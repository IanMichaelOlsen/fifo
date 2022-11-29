/*********************
* Name: Ian Olsen
* Assignment: Challenge 2
* Date: 11/28/2022
* FIFO STACK
*********************/

#ifndef FIFO_FIFO_H
#define FIFO_FIFO_H

#include "string"
#include "iostream"
using std::string;

//LITERALS
int const STACKSIZE = 10;

struct Data {
    int id;
    string information;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

//FIFO stack
class Fifo {

public:
    Fifo();
    ~Fifo();
    bool push(int, string&);
    bool pull(Data&);
    bool peek(Data&);
    bool isEmpty();
    void dumpStack();

private:
    Node *head;
    Node *tail;
    int size;

};

////Singly Linked list that implements a queue using node and data struct.
////List will user a tail pointer and head pointer to keep track of the list.
////The list will be able to add and remove nodes from the list.
////The list will be able to print the list.
////The list will be able to check if the list is empty.
////The list will be able to peek at the next node to be removed.



#endif //FIFO_FIFO_H
