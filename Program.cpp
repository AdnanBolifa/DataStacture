#include <iostream>
#include "Automata.h"
#include "DataStructures.h"
#include "DsHomework.h"
#include <fstream>
using namespace std;

void deleteProduct(Product products[], int& numProducts, const string& name, Stack& undoStack)
{
    Homework ds;
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

void undoDelete(Product products[], int& numProducts, Stack& undoStack) {
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
int main() 
{ 
    DataStracture ds;
    Automata autom;
    Homework hw;

    autom.FileSearch("MyFile.txt");
    string word;

    /*cout << "Language L which: L = {x01y : x,y < {0,1}* }.\n";
    cout << "Enter your word: ";
    getline(std::cin, word);
    autom.ValidWord(word);*/

    //const int MAX_PRODUCTS = 100;
    //Product products[MAX_PRODUCTS];
    //int numProducts = 0;

    //Product p1 = { "iPhone x", 1, 20, 400 };
    //Product p2 = { "iPhone 11", 2, 60, 600 };
    //Product p3 = { "iPhone 14", 3, 2, 800 };
    //Product p4 = { "iPhone 6", 4, 7, 100 };

    //hw.addProduct(products, numProducts, p1);
    //hw.addProduct(products, numProducts, p2);
    //hw.addProduct(products, numProducts, p3);
    //hw.addProduct(products, numProducts, p4);

    //int index = hw.findProduct(products, numProducts, "iPhone 14");
    //cout << "Product found: " << products[index].price << endl;
    //////
    //Product p6 = { "iPhone 8", 4, 7, 100 };
    //hw.editProduct(products, numProducts, "iPhone 6", p6);
    //index = hw.findProduct(products, numProducts, "iPhone 8");
    //if (index != -1) {
    //    cout << "Product found: " << products[index].name << endl;
    //}
    //else {
    //    cout << "Product not found" << endl;
    //}
    //Stack undoStack;
    //deleteProduct(products, numProducts, "iPhone 11", undoStack);
    //undoDelete(products, numProducts, undoStack);
    //for (size_t i = 0; i < numProducts; i++)
    //{
    //    cout << products[i].name << endl;;
    //}

}