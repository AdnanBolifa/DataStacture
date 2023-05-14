#pragma once
#include <iostream>
using namespace std;

struct Product
{
    string name;
    int id;
    int amount;
    double price;
};
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
            return { "", 0, 00, 0 };
        }
        return data[topIndex];
    }
    bool empty() const {
        return topIndex == -1;
    }
};

class Homework
{
public:

    void addProduct(Product products[], int& numProducts, const Product& p) {
        products[numProducts] = p;
        numProducts++;
    }
    int findProduct(const Product products[], int numProducts, const string& name) {
        for (int i = 0; i < numProducts; i++) {
            if (products[i].name == name) {
                return i;
            }
        }
        return -1;
    }
    void editProduct(Product products[], int numProducts, const string& name, const Product& newProduct) {
        int index = findProduct(products, numProducts, name);
        if (index != -1) {
            products[index] = newProduct;
            cout << "Product edited: " << products[index].name << endl;
        }
        else {
            cout << "Product not found" << endl;
        }
    } 
    void sellProduct(Product products[], int numProducts, const string& name) {
        int index = findProduct(products, numProducts, name);
        if (index != -1) {
            if (products[index].amount > 0) {
                products[index].amount--;
                cout << "Product bought: " << products[index].name << endl;
            }
            else {
                cout << "Product out of stock" << endl;
            }
        }
        else {
            cout << "Product not found" << endl;
        }
    }
    void buyProduct(Product products[], int numProducts, const string& name) {
        int index = findProduct(products, numProducts, name);
        if (index != -1) {
            products[index].amount++;
            cout << "Product sold: " << products[index].name << endl;
        }
        else {
            cout << "Product not found" << endl;
        }
    }
};
