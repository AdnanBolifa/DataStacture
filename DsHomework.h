#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "stack"
using namespace std;

struct Product 
{
    string name;
    int id;
    int amount;
    double price;
};
class Homework1
{
public:
	Homework1();
	~Homework1();
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
    void deleteProduct(Product products[], int& numProducts, const string& name) {
        int index = findProduct(products, numProducts, name);
        if (index != -1) {
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
    void deleteProduct(Product products[], int &numProducts, const string &name) {
    int index = findProduct(products, numProducts, name);
    if (index != -1) {
        for (int i = index; i < numProducts - 1; i++) {
            products[i] = products[i + 1];
        }
        numProducts--;
        cout << "Product deleted" << endl;
    } else {
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
    void undoDelete(Product products[], int& numProducts, stack<Product>& undoStack) {
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

private:

};

Homework1::Homework1()
{
}

Homework1::~Homework1()
{
}
