//****************************************************************************
// Author:      Greg Shenefelt
// Assignment:  Homework Three
// Date:        August 10th 2022
// Description: This program reads in dynamic cstrings of user input to get a filename from the user
//              then a dynamic list is created that stores a word object for each word in the file.
//
// add, remove, and see grades
// Inputs: 		A file name the user wants to have counted.
// Outputs:		A unique list of words containing the count of each word.
// Sources:		cplusplus.com, zybooks, professor.
//****************************************************************************
#include "word.h"
#include <iostream>
#include <cstring>


using namespace std;

//default constructor
word::word() {
    data = nullptr; // right sized array so this must start as nullptr.
    count = 0;
}

word::word(const char * datum)
{
    this->data = new char[strlen(datum) + 1];
    strcpy(this->data, datum);
    this->count = 1;
}

//destructor
word::~word() {

    if(data){
        delete []data;
        data = nullptr;
    }

}

//copy constructor
word::word(const word &source) {

    data = nullptr;
    *this = source;
}

//overloaded assignment operator
word & word::operator=(const word &source) {

    if(this == &source) {
        return *this;
    }

    if(data)
    {
        delete []data;

    }

    if(source.data != nullptr)
    {
        this->data = new char[strlen(source.data) + 1];
        strcpy(this->data, source.data);

    }
    else
    {
        data = nullptr;
    }
    this->count = source.count;

    return *this;
}

void word::SetData(const char * datum) {

    // if we already have a data pointer delete it.
    if(data)
    {
        delete []data;
    }

    data = new char[strlen(datum) + 1];
    strcpy(data,datum);

}

void word::GetData(char * datum) const {
    strcpy(datum, data);
}

void word::PrintData() {
    cout <<"Word: " << "\"" << data << "\"" << " "
         << "Count: " << count << endl;
}

void word::IncrementCount() {
    count++;
}

int word::GetWordLength() const {
    return strlen(data);
}

int word::GetCount() const {
    return count;
}

void word::SetCount(const int newCount) {
    count = newCount;
}
