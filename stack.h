#pragma once
#include <iostream>
using namespace std;
//stack class for controlling

class Stack1 {
    static const int MAX_SIZE = 100;
    Product data[MAX_SIZE];
    int topIndex;
public:
    Stack1() : topIndex(-1) {}
    void push(const Product& p) {
        if (topIndex == MAX_SIZE - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        topIndex++;
        data[topIndex] = p;
    }
    void pop() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        topIndex--;
    }
    Product top() const {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return { "", 0, 0, 0.0 };
        }
        return data[topIndex];
    }
    bool empty() const {
        return topIndex == -1;
    }
};
