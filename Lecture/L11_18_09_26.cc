#include <iostream>
#include <vector>
#include <string>

using namespace std;

// linked list intro
struct Student
{
    string name;
    int age;
    Student* next; // 
};


int main()
{

    Student* s0 = new Student;
    Student* s1 = new Student;

    s0->age = 20;
    s0->name = "Bob";

    s1->age = 47;
    s1->name = "Jeff";

    // make a list connecting the two. Make Bob node point to Jeff node
    s0->next = s1;

    s1 = new Student; // this is fine because we still have a link to the Jeff node, given by s0->next = s1; !
    s1->name = "Frank";
    s1->age = 34;

    // Now want to connect Jeff to Frank
    s0->next->next = s1; // Gets you to from Bob to Jeff to Frank. Sets the value of Jeff's 'next' var to the address of Frank's node

    s1->next = NULL; // standard way of ending a linked list

    return 0;
}