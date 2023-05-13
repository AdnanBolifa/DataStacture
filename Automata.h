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
    string line5[100][100];
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
            //cout << NOL(fileName) << endl;
            char ch;

            while (1)
            {
                nextChar:
                    myfile >> noskipws >> ch;
                if (myfile.eof())
                    break;
                if (ch == '\n') 
                {
                    numLines++;
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
                    break;
                }
            }
            cout << line1 << endl;
            cout << line2 << endl;
            cout << line3 << endl;
            cout << line4 << endl;
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
