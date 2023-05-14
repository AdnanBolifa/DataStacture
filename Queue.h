#pragma once
#include <iostream>

using namespace std;

class Queue 
{
private:
    int arr[10];
    int front;
    int rear;
    int capacity;
    int count;
public:
    Queue(int size = 10) 
    {
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    void push(int val) {
        if (isFull())
            cout << "Queue is full" << endl;
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }
    void pop() {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        front = (front + 1) % capacity;
        count--;
    }
    int getFront() {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        return arr[front];
    }
    int getRear() {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        return arr[rear];
    }
    int size() {
        return count;
    }
    bool isEmpty() {
        return (size() == 0);
    }
    bool isFull() {
        return (size() == capacity);
    }
};