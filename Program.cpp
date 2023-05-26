#include <iostream>
#include "Automata.h"
#include "DataStructures.h"
#include "DsHomework.h"
#include <fstream>
using namespace std;



void DisplayArray(string arr[], int size)  // Clear
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
    //cout << "Enter your word: ";
    //string word; cin >> word;
    //Automata autom("MyFile.txt", word);
    saleSystem();
    return 0;
}