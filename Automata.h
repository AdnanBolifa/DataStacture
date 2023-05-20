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
            return;
        }
        string temp;
        getline(myfile, temp);
        AddToArray(states, temp);

        getline(myfile, temp);
        sizeOfAlpha = removeSpaces(temp);
        AddToArray(alphabet, temp);

        getline(myfile, startState);

        getline(myfile, temp);
        AddToArray(endState, temp);

        for (int i = 0; i < NOL() - 4 && getline(myfile, temp); i++)
        {
            getline(myfile, temp);
            AddTo2DArray(transition_table, temp, i);
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
                if (temp != currentState)//TODO 
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
    bool ValidWord(string word)
    {
        //word.find_first_not_of("01"); ???
        for (char c : word)
        {
            bool charIsValid = false;
            for (string validChar : alphabet)
            {
                if (c == validChar[0])
                {
                    charIsValid = true;
                    break;
                }
            }
            if (!charIsValid)
            {
                cout << c << ": is not a valid character!\n";
                return false;
            }
        }
        return true;
    }//By chatGPT
    int removeSpaces(string str)
    {
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
                j++;
            else
                arr[j] += temp[i];
        }
    }
    void AddTo2DArray(string(&arr)[MAX_SIZE][MAX_SIZE], string line, int row)
    {
        int j = 0;
        for (int i = 0;i < line.length(); i++)
        {
            if (line[i] == ' ')
                j++;
            else
                arr[row][j] += line[i];
        }
    }  
};
