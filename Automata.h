#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Automata
{
public:
    Automata();
    ~Automata();

    string line1;
    string line2;
    string line3;
    string line4;
    string line5;
    
    char ch;
    int numLines = 0;

    void FileSearch(string fileName)
    {
        int numLines = 0;
        string line;
        ifstream myfile(fileName);
        if (!myfile)
        {
            cout << "No such file";
        }
        else
        {
            int rows = NOL(fileName) - 4;
            int cols = 5;
            string** _2D = new string* [rows];
            for (int i = 0; i < rows; i++)
                _2D[i] = new string[cols];

            char ch;
            int j = 0, i = 0;
            while (1)
            {
                
            nextChar:
                    myfile >> noskipws >> ch;
                if (myfile.eof())
                    break;
                if (ch == '\n') 
                {
                    numLines++;
                    j = 0;
                    goto nextChar;
                }

                switch (numLines)
                {
                case 0:
                    line1 += ch;
                    break;
                case 1:
                    line2 += ch;
                    break;
                case 2:
                    line3 += ch;
                    break;
                case 3:
                    line4 += ch;
                    break;
                default:
                    _2D[i][j++] = ch;
                    break;
                }
                i++;
            }
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < cols; j++)
                {
                    cout<<_2D[i][j];
                }
                cout << endl;
            }
            for (int i = 0; i < rows; i++)
                delete[] _2D[i];
            delete[] _2D;
        }
        myfile.close();
        
    }
    
private:
    int NOL(string fileName)
    {
        ifstream myFile(fileName);
        string line;
        int count = 0;
        while (!myFile.eof())
        {
            getline(myFile, line);
            count++;
        }
        myFile.close();
        return count;
    }
};

Automata::Automata()
{
}

Automata::~Automata()
{
}
