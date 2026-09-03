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
using namespace std;

// a pointer stores an address, not a "value" like a regular int, or char...

int main()
{

    int* p;
    int x;

    p = &x;

    double y;
    double* ptr;
    
    ptr = &y;

    *p = 7;
    int z;
    z = *p;

    cout << *p << endl;
    cout << x << endl;
    cout << z << endl;
    
    cout << p << endl;
    cout << &p << endl;

    int* p2 = p; // p2 points to the same place p points to

}