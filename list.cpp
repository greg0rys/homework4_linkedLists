#include "list.h"

// default constructor
list::list()
{
    head = nullptr;
    size = 0;
}

//copy constructor
list::list(const list &master){
    head = nullptr;
    *this = master;
}

//overloaded copy assignment operator
list & list::operator=(const list &master){
    if(this == &master){
        return *this;
    }

    if(head)
    {
        delete head;
    }

    if(master.head)
    {
        head = master.head;
    }
    else
    {
        head = nullptr;
    }
    size = master.size;

    return *this;
}

// list destructor
list::~list(){

    node * curr = head;
    while(curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }

    cout << "List destructed " << endl;
}

// helper to call the private method
void list::insert(word &word)
{
    insertNode(head, word);
}

// maintain a sorted linked list
void list::insertNode(node *&head,  word &word){

    node * newNode = nullptr;
    node * prevNode = nullptr;
    node * curr = head;
    char * headWord = nullptr;
    char * paramWord = nullptr;

    if(head == nullptr)
    {
        cout << "First word! " << endl;
        newNode = new node();
        newNode->data = &word;
        head = newNode;
        head->next = nullptr;
    }
    else
    {

        while(curr)
        {
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
            if(paramWord != nullptr)
            {
                delete []paramWord;
                paramWord = new char[word.GetWordLength() + 1];
                word.GetData(paramWord);
            }
            else
            {
                paramWord = new char[word.GetWordLength() + 1];
                word.GetData(paramWord);
            }

            if(strcmp(headWord, paramWord) == 0)
            {
                // if the words are the same increase the count by 1.
                curr->data->IncrementCount();
                delete []headWord;
                delete []paramWord;
                return; // word is a duplicate do nothing.
            }

            if(curr->data->GetWordLength() == word.GetWordLength())
            {
                if(strcmp(headWord, paramWord) > 0)
                {
                    break;
                }
            }

            if(curr->data->GetWordLength() > word.GetWordLength())
            {
                break;
            }

            prevNode = curr;
            curr = curr->next;
        }

        // insert at front of the list?
        if(curr == head)
        {
            newNode = new node();
            newNode->data = &word;
            newNode->next = head;
            head = newNode;
        }
        // inserting else where in the list
        else
        {
            newNode = new node();
            newNode->data = &word;
            newNode->next = curr;
            prevNode->next = newNode;
        }


    }

    size++;

    if(headWord){
        delete []headWord;
    }
    if(paramWord){
        delete []paramWord;
    }


}

// delete items from the sorted list
void list::deleteNode(node *&head, const word &word){

}

int list::getSize() const {
    return size;
}

void list::printList()
{
    node * curr;
    char * wordData = nullptr;
    for(curr = head; curr; curr=curr->next)
    {
        if(wordData != nullptr)
        {
            delete []wordData;
            wordData = new char[curr->data->GetWordLength() + 1];
            curr->data->GetData(wordData);

        }
        else
        {
            wordData = new char[curr->data->GetWordLength() + 1];
            curr->data->GetData(wordData);

        }

        cout << wordData << endl;
        cout << curr->data->GetCount() << endl;
    }

    if(wordData)
    {
        delete []wordData;
    }
}