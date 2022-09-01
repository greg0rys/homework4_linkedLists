//****************************************************************************
// Author:      Greg Shenefelt
// Assignment:  Homework Two
// Date:        August 10th 2022
// Description: This program reads in dynamic cstrings of user input to get a filename from the user
//              then a dynamic list is created that stores a word object for each word in the file.
//
// add, remove, and see grades
// Inputs: 		A file name the user wants to have counted.
// Outputs:		A unique list of words containing the count of each word.
// Sources:		cplusplus.com, zybooks, professor.
//****************************************************************************
#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;



class word {
public:
    word();
    word(const word &);
    word(const char *);
    ~word();
    word & operator=(const word &);
    void SetData(const char *);
    void GetData(char *) const;
    void PrintData();
    void IncrementCount();
    int GetWordLength() const;
    int GetCount() const;
    void SetCount(const int);
private:
    char * data;
    int count;
};