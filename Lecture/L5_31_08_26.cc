/*
Topics:
    - The pointer variable
    - Function parameters
        - Pass-by-value
        - Pass-by-reference
        - Pass-by-pointer
        - Pass-by-array
*/
#include <iostream>

// a pointer stores an address, not a "value" like a regular int, or char...

int main()
{

    int* p; // declares an integer pointer named p. an address is a non-zero integer
    double* ptr;
    char* p0;

    // the above will all store addresses, but the data type of the pointer must match the type of data the address points to

    int x = 13;

    p = &x; // p stores the address of x. & is the address-of-operator

    double y;
    ptr = &y;

    *p = 7; //de-referencing the pointer to access the value at the address

    p = nullptr; // write 0 to pointer p

    int* q;
    *q = 9;

    int z;
    z = *q;

    std::cout << *q << std::endl;
    std::cout << q << std::endl;

}