#pragma once
#include "word.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class list
{
private:
    struct node
    {
        word * data;
        node * next;

        node()
        {
            data = nullptr;
            next = nullptr;
        }

        node(word &aWord)
        {
            data = &aWord;
            next = nullptr;

        }

    };
    int size;
    node * head;
    void insertNode(word &word);
    void deleteNode(node *&, const word &word);
public:
    list();
    list(const list &);
    list &operator=(const list &);
    ~list();
    void insert(word &);
    void removeItem(const word &word);
    void printList();
    int getSize() const;


};