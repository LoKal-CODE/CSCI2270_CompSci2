#include <iostream>
#include <string>

using namespace std;

// pointers to structs
struct Student
{
    string name;
    int age;
};

class Robot
{
    private:
        string name;
        int batLevel;

    public:
        void setName(string n)
        {
            name = n;
        }
};


int main(void)
{
    
    Student s0;
    Student* sptr = NULL;

    s0.age = 344;
    s0.name = "Pat";

    sptr = &s0;

    sptr -> name = "Bob";
    sptr -> age = 34;

    Robot* myRobot = new Robot();

    myRobot -> setName("Randy");

    return 0;
}