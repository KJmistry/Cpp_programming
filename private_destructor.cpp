#include <iostream>

using namespace std;

class base
{
    ~base()
    {
        cout << "destructor called" << endl;
    }
public:
    base()
    {
        cout << "constructor called" << endl;
    }

    void dealloc()
    {
        delete this;
    }
};

int main()
{   
    base *oPtr = new base;
    oPtr->dealloc();
    return 0;
};