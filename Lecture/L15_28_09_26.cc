#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* next;
};


// recursion
// a function that calls another instance of itself if a certain condition is met
// For a valid recursive algorithm, the algorithm needs to eventually reach a base case, so it can terminate

void printRecursive( int n )
{

    if (n == 0)
    {
        return;
    }
    
    cout << "n = " << n << endl;
    printRecursive(n - 1);
    
    return;

}

int fact( int n )
{
    if (n > 1)
    {
        return n * fact(n - 1);
    }
    else {
        return 1;
    } 
}

// recursion and linked lists

// counting nodes
int length( Node* curr )
{
    if (curr == nullptr)
    {
        return 0;
    }
    
    return 1 + length( curr->next );
    
}

// print in reverse
void printReverse( Node* curr )
{
    if (curr == nullptr)
    {
        return;
    }
    
    printReverse( curr->next );
    cout << curr->key << " ";
    
}

// recursive append
Node* append( Node* curr, int val )
{
    if (curr == nullptr)
    {
        Node* newNode = new Node;
        newNode->key = val;
        newNode->next = nullptr;
        return newNode;
    }
    
    curr->next = append(curr->next, val);
    return curr;
    
}

int main( int argc, char* argv[] ) 
{

    printRecursive(5); 

    int out = fact(5);

    cout << out << endl;

    return 0;
}
