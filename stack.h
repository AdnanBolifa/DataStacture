#include <iostream>

using namespace std;

class stack1
{
    static const int M = 100;
    int ara[M]; // declared an array for storing the stack elemenst
    int top; // finding the top value
public:
    //function for pushing values into the stack
    stack1() // constructor for initializing
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


