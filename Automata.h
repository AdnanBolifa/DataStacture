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
	
    void FileSearch(string fileName)
    {
        int numLines = 0;
        string line;
        ifstream myfile(fileName);
        if (!myfile) {
            cout << "Error opening output file" << endl;
        }
        while (getline(myfile, line)) {
            numLines++;
        }
        myfile.clear();
        myfile.seekg(0, ios::beg);
        string* lines = new string[numLines];
        int i = 0;
        while (getline(myfile, line)) {
            lines[i] = line;
            i++;
        }
        cout << lines[0][0];
    }

private:

};

Automata::Automata()
{
}

Automata::~Automata()
{
}
