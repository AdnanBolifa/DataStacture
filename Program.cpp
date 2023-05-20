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
void DisplayArray(string arr[], int size, bool is2D)  // Clear
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}
void Display2dArray(string arr[][25], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{ 
    DataStracture ds;
    Homework hw;
    string word;

    string al[2] = { "0","1" };
    string word;

    cout << "Enter your word: ";
    cin >> word;

    for (int i = 0; i < word.length(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            
        }
    }
    exit(0);
    char c;
    do
    {
        cout << "Language L which: L = {x<<01y : x,y < {0,1}* }\n";
        cout << "Enter your word: ";

        getline(std::cin, word);
        Automata autom("MyFile.txt", word);

        printf("\nPress any key except Enter to exit...\n");
        c = getchar(); // wait for user input
        if (c != '\n') { // check if input is not Enter key
            exit(0); // terminate the program
        }
    } while (c != 'q');
    return 0;
}