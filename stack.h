#pragma once
#include <iostream>
#define M 4 //defined the size of the stack ;
using namespace std;
//stack class for controlling

class stack
{
    int ara[M]; // declared an array for storing the stack elemenst
    int top; // finding the top value
public:
    //function for pushing values into the stack
    stack() // constructor for initializing
    {
        top = 0;
    }
    void push(int n)
    {
        if (top == M) // checking if the stack is full or not
        {
            cout << "Stack is full\n";
            return;
        }
        else // if the stack is not full, push the element
        {
            ara[top++] = n;
        }
    }
    //function for poping out elements from the stack or getting the elements
    int pop()
    {
        if (top == 0)
        {
            cout << "Stack is empty\n";
            return NULL;
        }
        else
        {
            top--;
            return ara[top];
        }
    }

};

