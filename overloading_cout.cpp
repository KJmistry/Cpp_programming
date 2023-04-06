#include <iostream>

using namespace std;

class base 
{
    int a;

public:
    base(int x = 10) : a(x) {}

    friend ostream & operator << (ostream &, base &);
};

ostream & operator <<(ostream &out, base &ref)                          // These operators must be overloaded as a global function
{
    cout << ref.a << endl;
    return out;
}
int main()
{
    base obj(90);
    cout << obj;
    return 0;    
}