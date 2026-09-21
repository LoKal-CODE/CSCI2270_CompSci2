#include <iostream>

#include "SLL.hh"

using namespace std;

SLL::SLL()
{
    head = NULL; 
}

Node* SLL::search( string sKey )
{
    Node* crawler = head; // use this as a temp pointer to iterate over the linked list, initialize it to the same place as head to start

    while ( crawler != nullptr && crawler->key != sKey ) // must have nullptr check first
    {
        crawler = crawler->next; // THIS IS A KEY LINE, like i++ but with pointers
    }

    return crawler;

}

int main()
{


    return 0;
}