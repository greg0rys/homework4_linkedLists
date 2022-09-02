#include "list.h"

// default constructor
list::list()
{
    index = nullptr;
    size = 0;
}

//copy constructor
list::list(const list &master){
    index = nullptr;
    *this = master;
}

//overloaded copy assignment operator
list & list::operator=(const list &master){
    if(this == &master){
        return *this;
    }

    if(index)
    {
        delete index;
    }

    if(master.index)
    {
        index = master.index;
    }
    else
    {
        index = nullptr;
    }
    size = master.size;

    return *this;
}

// list destructor
list::~list(){

    node * curr = index;
    while(curr)
    {
        index = curr->next;
        delete curr;
        curr = index;
    }

}


// maintain a sorted linked list
void list::insertNode( word &aWord){

    node * newNode = nullptr;
    node * prevNode = nullptr;
    node * curr = index;
    char * headWord = nullptr;
    char * paramWord = new char[aWord.GetWordLength() + 1];
    aWord.GetData(paramWord);

    // case 1 - inserting into an empty list.
    if(curr == nullptr)
    {
        newNode = new node(aWord);
        index = newNode;
    }
    else
    {

        // case 2 inserting into an already occupied list.

        while(curr)
        {
            // allocate data for the index of the list word and get the word each iteration
            if(headWord != nullptr){
                delete []headWord;
                headWord = new char[curr->data->GetWordLength() + 1];
                curr->data->GetData(headWord);
            }
            else
            {
                headWord = new char[curr->data->GetWordLength() + 1];
                curr->data->GetData(headWord);
            }


            // case 3 - the words are the same, don't add anything to the list.
            if(strcmp(headWord, paramWord) == 0)
            {
                // if the words are the same increase the count by 1.
                curr->data->IncrementCount();
                // since we will return from this function delete the char pointers
                // as we will never reach the end for the deletion statements.
                delete []headWord;
                delete []paramWord;
                return; // word is a duplicate do nothing.
            }

            if(strlen(headWord) < strlen(paramWord))
            {
                if(strcmp(headWord,paramWord) < 0){
                    break;

                }
            }

            // case 4 - the words are the same length, insert them via ascii order
            if(strlen(headWord) == strlen(paramWord))
            {
                if(strcmp(headWord, paramWord) < 0)
                {
                    break;
                }
            }



            prevNode = curr;
            curr = curr->next;
        }

        // insert at front of the list?
        if(curr == index)
        {
            newNode = new node(aWord);
            newNode->next = index;
            index = newNode;
        }
        // inserting else where in the list
        else
        {
            newNode = new node(aWord);
            newNode->next = curr;
            prevNode->next = newNode;
        }


    }

    size++;

    if(headWord){
        delete []headWord;
    }
    delete[]paramWord;


}


int list::getSize() const {
    return size;
}

void list::printList()
{
    node * curr;

    for(curr = index; curr; curr = curr->next)
    {
        curr->data->PrintData();
    }
}