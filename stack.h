#include <iostream>
#include "DsHomework.h"

using namespace std;

class Stack 
{
    
    static const int MAX_SIZE = 100;
    Product data[MAX_SIZE];
    int topIndex;
public:
    Stack() : topIndex(-1) {}
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
            return { "", 0, 0, 0 };
        }
        return data[topIndex];
    }
    bool empty() const {
        return topIndex == -1;
    }
    static void deleteProduct(Product products[], int& numProducts, const string& name, Stack& undoStack)
    {
        Homework1 ds;
        int index = ds.findProduct(products, numProducts, name);
        if (index != -1) {
            undoStack.push(products[index]);
            for (int i = index; i < numProducts - 1; i++) {
                products[i] = products[i + 1];
            }
            numProducts--;
            cout << "Product deleted" << endl;
        }
        else {
            cout << "Product not found" << endl;
        }
    }

    static void undoDelete(Product products[], int& numProducts, Stack& undoStack) {
        if (!undoStack.empty()) {
            Product p = undoStack.top();
            undoStack.pop();
            products[numProducts] = p;
            numProducts++;
            cout << "Undo successful: " << p.name << endl;
        }
        else {
            cout << "Nothing to undo" << endl;
        }
    }
};


