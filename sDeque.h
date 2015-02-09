#ifndef SDEQUE_H_INCLUDED
#define SDEQUE_H_INCLUDED
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

class Deque {
private:
    string *queue, remove;
    int num_elements, size_of_queue, head, tail,previousHead,previousTail,minSize;// dont think I need a "start" variable;
public:
    Deque();//Default constructor
    void grow(int, string*); //Doubles the size of the queue when needed
    void shrink(int, string*); //Halves the size of the queue when needed
    ~Deque(); //Destructor
    void push_front(string);//adds elements to the front of the queue
    void push_back(string);//adds elements to the back of the queue
    string pop_front();//removes the element at the front of the queue
    string pop_back();//removes the element at the back of the queue
    int size();//returns the size of the array
    bool empty();//returns true if the queue is empty
    string toStr();
    void print_queue();//prints the queue
};


#endif // SDEQUE_H_INCLUDED
