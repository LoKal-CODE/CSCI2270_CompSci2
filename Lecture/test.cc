#include <iostream>

int main()
{   

    std::cout << "Hello\n";

    bool a = false;

    if (a == true) {
        std::cout << "a is true\n";
    } else {
        std::cout << "a is false\n";
    }

    bool b = true;
    int flag = 0;

    while (b)
    {
        std::cout << "b is true\n";
        flag++;
        
        if (flag == 5)
        {
            b = false;
        }
        

    }
    


    return 0;

}
