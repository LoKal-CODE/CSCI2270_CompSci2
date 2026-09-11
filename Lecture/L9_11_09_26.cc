#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{

    int* a = new int[5]; // creates an integer array of 5 elements

    int* b = new int(5); // is the same as int* b; *b = 5;

    delete a;
    delete b;
    a = NULL;
    b = NULL;

    // array doubling

    int n = 3;
    int* c = new int[n];
    int* temp = new int[2 * n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }
    delete[] c; // delete BEFORE c = temp to not cause memory leak by pointing c to a different array before deallocating it (if you dealloc then, then you would be deallocing the new, bigger array)
    c = temp; // address of c is now that of the new, bigger array in heap memory
    temp = NULL; // good practice, remove the value stored in temp by setting it to NULL or nullptr
    n = 2*n;
    
    delete[] temp;
    c = NULL;
    temp = NULL; 

    return 0;
}