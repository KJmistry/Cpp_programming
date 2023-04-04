#include <iostream>

using namespace std;

int function()
{   
    static int k = 0;                       // non static members are not accessible to loacl class
    
    class B
    {
        int b;
    
    public:
        B()
        {
            cout << "constructor of B called !" << endl;
        }
    };

    class A 
    {
        int a;                              // static members are not allowed

    public:
        A(int t)
        {
            a = t;      
            k = t;
            B b;                            // another local class is accessed by class A
        }

        void display()                      // defination outside class is not allowed (using className :: func)
        {
            cout << " a + 10 = " << a + 10 << endl;
        }
    };
    

    A obj(20);
    obj.display();
    return k;
}

int main()
{
    int a = function();
    cout << "value of 'a' was " << a << endl;
    return 0;
}