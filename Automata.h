#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Automata
{
public:
    static const int MAX_SIZE = 25;
    Automata(string fileName, string word) 
   {
       this->fileName = fileName;
       this->word = word;
       FileSearch();
       nextState();
   }
    int sizeOfAlpha;

    string states[MAX_SIZE];
    string alphabet[MAX_SIZE];
    string startState;
    string endState[MAX_SIZE];
    string transition_table[MAX_SIZE][MAX_SIZE];
private:
    string fileName;
    string word;
    void FileSearch()
    {
        ifstream myfile(fileName);
        if (!myfile)
        {
            cout << "No such file";
        }
        else
        {
            string temp;
            getline(myfile, temp);
            AddToArray(states, temp);

            getline(myfile, temp);
            sizeOfAlpha = removeSpaces(temp);
            AddToArray(alphabet, temp);

            getline(myfile, temp);
            startState = temp;

            getline(myfile, temp);
            AddToArray(endState, temp);

            for (int i = 0; i < NOL() - 4; i++)
            {
                getline(myfile, temp);
                AddTo2DArray(transition_table, temp, i);
            }
        }
        myfile.close();
    }
    void nextState()
    {
        if (ValidWord(word))
        {
            int rows = 0;
            int j = 0;
            string currentState = startState;
            for (int i = 0; i < word.length(); i++)
            {
                string temp = currentState;
                while (j != sizeOfAlpha)
                {
                    if (alphabet[j] == string(1, word[i]))//01
                        currentState = transition_table[rows][j];
                    j++;
                }
                if (temp != currentState)
                {
                    rows++;
                    j = 0;
                }
                j = 0;

            }
            cout <<"Current state: " << currentState << "\n";
            if (currentState == endState[0])
                cout << "\tAccepted!..\n";
            else
                cout << "\tNot Accepted!..\n";
        }
    }
    int NOL() // number of lines
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
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (alphabet[i] == string(1, chr))
                return true;
        }
        return false;
    }
    bool ValidWord(string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (!ValidAlphabet(word[i])) {
                cout << word[i] << " not a valid charecter!\n";
                return false;
            }

        }
        return true;
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
    int removeSpaces(string str)
    {
        // To keep track of non-space character count
        size_t pos = str.find(' ');
        while (pos != std::string::npos) {
            str.replace(pos, 1, "");
            pos = str.find(' ');
        }
        return str.length();
    }
    void AddToArray(string(&arr)[MAX_SIZE], string temp)
    {
        int j = 0;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == ' ')
            {
                j++;
                continue;
            }
            arr[j] += temp[i];

        }
    }
    void AddTo2DArray(string(&arr)[MAX_SIZE][MAX_SIZE], string temp, int row)
    {
        int j = 0;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == ' ')
            {
                j++;
                continue;
            }
            arr[row][j] += temp[i];
        }
    }  
};
