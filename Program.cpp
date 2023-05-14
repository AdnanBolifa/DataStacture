#include <iostream>
#include "stack.h"
#include "Automata.h"
#include "DataStructures.h"
#include "DsHomework.h"
#include <fstream>
using namespace std;

int main() 
{ 
    DataStracture ds;
    Automata autom;
    Homework hw;
    //autom.FileSearch("MyFile.txt");
    const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    Product p1 = { "iPhone x", 1, 20, 400 };
    Product p2 = { "iPhone 11", 2, 60, 600 };
    Product p3 = { "iPhone 14", 3, 2, 800 };
    Product p4 = { "iPhone 6", 4, 7, 100 };

    hw.addProduct(products, numProducts, p1);
    hw.addProduct(products, numProducts, p2);
    hw.addProduct(products, numProducts, p3);
    hw.addProduct(products, numProducts, p4);

    int index = hw.findProduct(products, numProducts, "iPhone 14");
    cout << "Product found: " << products[index].price << endl;
    ////
    Product p6 = { "iPhone 8", 4, 7, 100 };
    hw.editProduct(products, numProducts, "iPhone 6", p6);
    index = hw.findProduct(products, numProducts, "iPhone 8");
    if (index != -1) {
        cout << "Product found: " << products[index].name << endl;
    }
    else {
        cout << "Product not found" << endl;
    }
    ////
    Stack undoStack;
    undoStack.deleteProduct(products, numProducts, "iPhone 11", undoStack);
    undoStack.undoDelete(products, numProducts, undoStack);
    for (size_t i = 0; i < numProducts; i++)
    {
        cout << products[i].name << endl;;
    }
 

    
    

}