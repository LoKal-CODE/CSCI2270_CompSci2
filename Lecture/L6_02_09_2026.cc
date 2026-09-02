#include <iostream>

using namespace std;


void foo( int* x )
{
    *x = 0;
}


// pass-by-value
void myPBV( int x )
{
    x = -7;
} 
// does not update the variable value in the global scope, only the local function scope. 'int x' is a copy of the main parameter passed, not a link to the actual variable.

// pass-by-reference


// pass-by-pointer
void myPBP( int* x )
{
    *x = -7;
}
// DOES update the main/global variable value, given that myPBP takes in the actual memory address of what is passed in, not a copy like with PBV.

int main()
{

    int y = 8;
    int *p = &y;
    int* z = NULL; // OR int* z = nullptr;
    
    foo(p);

    cout << y << endl;

    return 0;
}