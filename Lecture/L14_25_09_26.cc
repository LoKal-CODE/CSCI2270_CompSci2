#include <iostream>
#include <string>
#include <random>

using namespace std;

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
        void deleteNode(string key);

};

SLL::SLL()
{
    head = NULL; 
}

SLL::~SLL()
{
    Node* crawler;
    while (head != NULL)
    {
        crawler = head->next;
        delete head;
        head = crawler;
    }
    
}

void SLL::deleteNode(string deleteKey)
{

    if (deleteKey == head->key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    else {
        Node* prev, *crawler = head;
        bool found = false;

        while (crawler != NULL && !found)
        {
            if (crawler->key == deleteKey)
            {
                found = true;
            }
            
            else {
                prev = crawler;
                crawler = crawler->next;
            }
            
        }
        
        if (found)
        {
            // re-connect the LL around the node about to be removed
            prev->next = crawler->next;
            // dealloc
            delete crawler;
        }

    }
    

}

int main()
{

    // algortithmic complexity
    // big-O notation:
    /*
    
    Drop all units and constants (ex. N+3, drop the +3)
    
    O(N)
    describes the theoretical upper bound of an algorithm as N->infinity

    The best possible complexity? O(1) -> the algorithm is not affected by the number of elements

    ex. 3n^2 + 5n + 3 is O(n^2)
    
    
    */

    
    return 0;
}