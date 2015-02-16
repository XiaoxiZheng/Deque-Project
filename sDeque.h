#ifndef SDEQUE_H_INCLUDED
#define SDEQUE_H_INCLUDED
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include<string>

using namespace std;

template <class T>
class Deque {
private:
    T *queue, remove;
//    string *queue, remove;

    int num_elements, size_of_queue, head, tail,previousHead,previousTail,minSize;// dont think I need a "start" variable;

public:
    Deque();//Default constructor
    void grow(int, T*); //Doubles the size of the queue when needed
    void shrink(int, T*); //Halves the size of the queue when needed
    ~Deque(); //Destructor
    void push_front(T);//adds elements to the front of the queue
    void push_back(T);//adds elements to the back of the queue
    T pop_front();//removes the element at the front of the queue
    T pop_back();//removes the element at the back of the queue
    int size();//returns the size of the array
    bool empty();//returns true if the queue is empty
    string toStr(); //the toStr() method the professor wants
    void print_queue();//prints the queue in another way
};


#endif // SDEQUE_H_INCLUDED
