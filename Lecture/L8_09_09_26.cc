#include <iostream>

using namespace std;


// retunring a pointer?
int* foo()
{
    int* x = nullptr;
    return x;
}
// it is allowed, but problematic

int* bar()
{
    int x[] = {7, 10, 21, 4, 5, 6, 7, 8, 9}; // !! THIS IS A BAD IDEA !!
    return x;
}
/*
*   Doing this is bad because the array lives in the stack frame of the function, which will be freed in memory after the return call, 
*   and then returning a pointer to "the" memory address of the array that is no longer there... but the compiler will not catch this
*/

int main( int argc, char* argv[] )
{

    // dynamic memory -> the heap
    int* p1;
    p1 = new int; // gives us an int's worth of memory, the pointer variable lives on the stack. new gives us the address of a piece of memory that it has allocated for us

    *p1 = 6; // read and write is the same as with local vars

    // we are now in charge of de-allocating the memory that we requested
    delete p1;

    // dynamic array declarations
    int* ptr;
    ptr = new int[5]; // now we get five int's worth of memory on the heap

    int* ptr2 = new int[5]; // same as the two-liner above

    delete [] ptr;
    delete [] ptr2;

    return 0;
}