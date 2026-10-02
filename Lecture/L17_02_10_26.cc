#include <iostream>
#include <string>

#define MAXSIZE 5

using namespace std;

// Queues
/*
- The queue is FIFO
- Limited to enqueue and dequeue methods
- enqueue - add an item at the tail (end) of the queue
- dequeue - remove the item at the head (front) of the queue
*/

// The Queue ADT
/*
Private (state)
- head -> the first/front item in the queue
- tail -> the last item in the queue (or for an array, the index right after the last item)
- queueSize -> number of elements currently in the queue

Public (operations)
- initialize() -> Constructor: 

*/

struct Node
{
    string item;
    Node* next;
};

class QueueLL
{

    private:
        Node* head;
        Node* tail;
        int queSize;
    
    public:
        QueueLL() {head = tail = nullptr; queSize = 0;}
        ~QueueLL() {while (!isEmpty()) dequeue();}

        bool isEmpty() {return head == nullptr;}

        void enqueue(string newItem)
        {
            Node* n = new Node;
            n->item = newItem;
            n->next = nullptr;

            if (isEmpty())
            {
                head = tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
            
            queSize++;
        }

        string dequeue()
        {
            if (isEmpty())
            {
                cerr << "QUEUE IS EMPTY, NOTHING TO DEQUEUE\n";
                return "";
            }
            
            Node* temp = head;
            string tempItem = temp->item; // for our function return
            head = head->next;

            if (head == nullptr)
            {
                tail = nullptr;
            }

            delete temp;
            queSize++;
            return tempItem;
        } 

};

// Linear Array Queue
/*
Rules:
- the head is always 0
- tail holds the index of the next available element
- dequeue removes a[0], then shifts every elements one to the left

- enqueue is O(1) but dequeue is O(n), not nice...
*/

// Circular Array Queue
/*
Both the tail and the head are permitted to move when we enqueue and dequeue. When an index runs off the end of the array, it wraps back around to 0
head = index of the front item
tail = index where the next item will go
Empty queue: head == tail ==0, queSize == 0
index = (index + 1) % MAXSIZE  -> advance w/ wrap around

for a circular queue, both enqueue and dequeue are O(1), nice!

*/



int main()
{


    return 0;
}