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
        node(){
            data = nullptr;
            next = nullptr;
        }

        node(const word &aWord) {

            data = new word(aWord);
            next = nullptr;
        }

        ~node(){
            if(data != nullptr)
            {
                delete data;
            }

            data = nullptr;
            next = nullptr;
        }

        word * data;
        node * next;

    };
    int size;
    node * head;
    void deleteNode(node *&, const word &word);
public:
    list();
    list(const list &);
    list &operator=(const list &);
    ~list();
    void insertNode(word &word);

    void removeItem(const word &word);
    void printList();
    int getSize() const;


};