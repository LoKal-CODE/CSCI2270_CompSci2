#include <iostream>
#include <string>
// #include <stack> -> the include to use the C++ Stack class

using namespace std;

#define MAXSIZE 9

/* The Stack ADT
*  The stack ADT is LIFO (last in, first out)
*  The stack is a limited-access data structure, you can only ever touch the top of the structure
*  push - add an item to the op
*  pop - remove the the item from the top
*  peek - look at the top item without removing it
*/

// implementing a Stack SLL
struct Node
{
    string item;
    Node* next;
};

class Stack
{
private:
    Node* top;
    int count;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(string newItem);
    void pop();
    Node* peek();
    void disp();
};

Stack::Stack(/* args */)
{
    top = nullptr;
    count = 0;
}

Stack::~Stack()
{
}

bool Stack::isEmpty()
{

    if (top == nullptr)
    {
        return true;
    } else {
        return false;
    }
    
    
}

void Stack::push(string newItem)
{

    Node* newNode = new Node;    
    newNode->item = newItem;
    newNode->next = top;
    top = newNode;
    count++;

}

void Stack::pop()
{

    if (isEmpty())
    {
        cout << "NOTHING TO POP, EMPTY STACK\n";
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
    count--;
}

Node* Stack::peek()
{

    return top;

}

void Stack::disp()
{
    // TODO:
}

Stack::~Stack()
{
    // TODO:
}

// what about a stack with arrays?
/*
class StackArr
{

    private:
        int top;
        int count;
        string a[MAXSIZE];

    public:
        StackArr();
        bool isEmpty();
        bool isFull();
        void push(string newItem);
        void pop();
        void disp();

};
*/

int main()
{

    // stack<int> nums; -> declares a stack of ints called nums


    return 0;
}