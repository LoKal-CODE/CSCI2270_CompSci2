// SLL.hh
#include <string>
using namespace std;

#ifndef SLL_H
#define SLL_H

struct Node
{
    string key;
    Node* next;
};

class SLL {

    private:
        Node* head;

    public:
        SLL(); // constructor
        ~SLL(); // destructor, needed when working with dynamic memory
        Node* search(string sKey);
        void displayList();
        void insert(string afterMe, string newValue);
        void deleteNode(Node* deleteNode);

};

#endif