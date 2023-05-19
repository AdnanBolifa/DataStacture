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


    string states;
    string alphabet;
    string startState;
    string endState;
    string transitionTable[10][10];
    
    void FileSearch(string fileName)
    {
        int numLines = 0;
        ifstream myfile(fileName);
        if (!myfile)
        {
            cout << "No such file";
        }
        else
        {
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
                    states += ch;
                    break;
                case 1:
                    alphabet += ch;
                    break;
                case 2:
                    startState += ch;
                    break;
                case 3:
                    endState += ch;
                    break;
                default:
                    for (size_t i = 0; i < NOL(fileName) - 4; i++)
                    {
                        for (size_t j = 0; j < 25; j++)
                        {
                            transitionTable[i][j] += ch;
                            myfile >> noskipws >> ch;
                            if (ch == '\n') {
                                myfile >> noskipws >> ch;
                                break;
                            }
                                
                        }
                    }
                    break;
                }
            }
        }
        myfile.close();
    }
    void putIntoArray()
    {

    }
    bool ValidWord(string word)
    {
        for (int  i = 0; i < word.length(); i++)
        {
            if (!ValidAlphabet(word[i])) {
                cout << word[i] << " not a valid chr\n";
                return false;
            }
                
        }
        return true;
    }

    string currentState;
    void NextState(string word)
    {
        if (ValidWord(word))
        {
            currentState = startState;
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == alphabet[0])
                {
                    
                }
            }
        }
    }


private:
    int NOL(string fileName) // number of lines
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
    bool ValidAlphabet(char chr)
    {
        for (int i = 0; i < alphabet.length(); i++)
        {
            if (alphabet[i] == chr) return true;
        }
        return false;
    }
    int numberOfCols(string alphabet)
    {
        int cols = 0;
        for (int i = 0; i < alphabet.length(); i++)
        {
            
            if (alphabet[i] != ' ')
                cols++;;
            
        }
        return cols;
    }
    void removeSpaces(string& str)
    {
        // To keep track of non-space character count
        int count = 0;

        // Traverse the given string. If current character
        // is not space, then place it at index 'count++'
        for (int i = 0; str[i]; i++)
            if (str[i] != ' ')
                str[count++] = str[i]; // here count is
        // incremented
        str[count] = '\0';
    }
    
};

Automata::Automata()
{
}

Automata::~Automata()
{
}
