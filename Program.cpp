#include <iostream>
#include "stack.h"
#include "Automata.h"
#include "DataStructures.h"
#include "DsHomework.h"
#include <fstream>
#include <stack>
using namespace std;

int main() 
{ 
    DataStracture ds;
    Automata autom;
    Homework1 hw;
    //autom.FileSearch("MyFile.txt");
    const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int numProducts = 0;
    Product p1 = { "iPhone", 1, 699.99, 10 };
    products[numProducts] = p1;
    numProducts++;
    int index = hw.findProduct(products, numProducts, "iPho6ne");
    if (index != -1) {
        cout << "Product found: " << products[index].name << endl;
    }
    else {
        cout << "Product not found" << endl;
    }
}