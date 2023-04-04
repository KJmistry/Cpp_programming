// C++ Program to demonstrate the
// functioning of a friend class
#include <iostream>
using namespace std;

class class1
{
    int Private = 10;

public:
    int Public = 100;

protected:
    int Protected = 1000;

friend class class2;

};

class class2
{
int a = 10;

public:
    void print(class1& ref)
    {
        cout << "Private : " << ref.Private  << endl;
        cout << "Public : " << ref.Public << endl;
        cout << "Protected : " << ref.Protected  << endl;
        return;
    }

};

int main()
{
    class1 obj1; 
    class2 obj2;
    obj2.print(obj1);
    return 0;
}