#include <iostream>

using namespace std;

// pass-by-reference
void myPBR(int &x)
{
    x = -7;
    return;
} // this WILL overwrite the value at x because it is passing the memory address of the callers variable. It does not get a copy of the callers variable, it gets the memory address of the variable
// it lets you worl like you would a pointer, but without the pointer syntax

// pass-by-array
void myPBA(int arr[])
{
    arr[0] = -7;
    return;
}
// when you pass an array, you pass a pointer or the address to the first element of the array, therefore it is similar to a pointer
// void myPBP(int* x)
// void myPBA(int x[])
// ARE IDENTICAL, they both pass an address

int main()
{

    int a = 2;
    cout << a << endl;
    myPBR(a);
    cout << a << endl;

    int arr[] = {5, 6};
    cout << arr[0] << endl;
    myPBA(arr);
    cout << arr[0] << endl;

    // STACK VS. HEAP (where we can allocate dynamic memory)
    // new and delete -> how we allocate dynamic memory. but we need to use a pointer!

    int *p1 = nullptr;
    p1 = new int; // we are given an int's worth of space on the heap

    return 0;
}
