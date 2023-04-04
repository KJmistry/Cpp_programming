#include <iostream>

using namespace std;

class base 
{
    int C = 30;

public:
    int A = 10;

protected:
    int B = 20;
    void print(){cout << C << endl;}
};

class derived : public base
{

    int c;

public:
    int a = B;
    void printPrivateMembersofBase()
    {
        print();
    }
protected:
    int b;
};

int main()
{
    derived B;
    cout << B.a << endl;
    cout << B.A << endl;                                    // won't work if derived as private since A will become private
    B.printPrivateMembersofBase();
    
    return 0;
}
