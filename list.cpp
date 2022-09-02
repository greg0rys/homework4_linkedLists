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


// maintain a sorted linked list
void list::insertNode( word &aWord){

    node * newNode = nullptr;
    node * prevNode = nullptr;
    node * curr = head;
    char * headWord = nullptr;
    char * paramWord = new char[aWord.GetWordLength() + 1];
    aWord.GetData(paramWord);
    word tempWord(paramWord);
    tempWord.GetData(paramWord);
    cout << paramWord << endl;

    if(curr == nullptr)
    {
        cout << "First word! " << endl;
        newNode = new node(tempWord);
        head = newNode;
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


            if(strcmp(headWord, paramWord) == 0)
            {
                // if the words are the same increase the count by 1.
                curr->data->IncrementCount();
                delete []headWord;
                delete []paramWord;
                return; // word is a duplicate do nothing.
            }

            if(curr->data->GetWordLength() == aWord.GetWordLength())
            {
                if(strcmp(headWord, paramWord) > 0)
                {
                    break;
                }
            }

            if(curr->data->GetWordLength() > aWord.GetWordLength())
            {
                break;
            }

            prevNode = curr;
            curr = curr->next;
        }

        // insert at front of the list?
        if(curr == head)
        {
            newNode = new node(tempWord);
            newNode->next = head;
            head = newNode;
        }
        // inserting else where in the list
        else
        {
            newNode = new node(tempWord);
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
    node * curr = head;
    char * wording = nullptr;
    while(curr)
    {
        if(wording)
        {
            delete []wording;
            wording = new char[curr->data->GetWordLength() + 1];
        }
        else
        {
            wording = new char[curr->data->GetWordLength() + 1];
        }
        curr->data->GetData(wording);
        cout << wording << " Count: " << curr->data->GetCount() << endl;
        curr = curr->next;
    }

    if(wording)
    {
        delete []wording;
        wording = nullptr;
    }

}