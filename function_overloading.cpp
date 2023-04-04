// PROGRAM 2 (Compiles and runs fine)
#include<iostream>
using namespace std;

class Test 
{
protected:
    int x;
 
public:
    Test(int i) : x(i)
    {
    }
    
    void fun() const
    {
        cout << "fun() const called " << endl;
    }

    void fun() 
    { 
        cout << "fun() called " << endl; 
    }
};

void fun(char *a)
{
    cout << "non-const fun() " << a;
}

void fun(const char *a)
{
    cout << "const fun() " << a;
}

int main()
{   
    Test t1(10);
    const Test t2(20);
    t1.fun();
    t2.fun();

    const char *ptr = "string";
    fun(ptr);
    return 0;
}
