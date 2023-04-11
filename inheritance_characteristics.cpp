#include <iostream>

using namespace std;

class BASE;

class OTHER
{
public:
    void privateAccess(BASE &ref);

    OTHER()
    {
        cout << "other constructor called" << endl;
    }
    ~OTHER()
    {
        cout << "other destructor called" << endl;
        // clear local members
    } 
};

class BASE 
{
    int a;
public:
    int b;

    friend void OTHER::privateAccess(BASE &);

    BASE(int a , int b ) : a(a) , b(b)
    {
        cout << "base constructor called" << endl;
    }
    virtual ~BASE ()
    {
        cout << "base destructor called" << endl;
        // clear loacl members 
    } 
};

class DERIVED : public BASE
{
    int A;

public:
    int B;
    DERIVED(int A, int B , int a = 0, int b = 0) : BASE(a,b) , A(A) , B(B) 
    {
        cout << "derived constructor called" << endl;
    }
    ~DERIVED()
    {
        cout << "derived destructor called" << endl;
        // clear local members
    } 
};


void OTHER::privateAccess(BASE &ref)
{
    cout << "BASE.a = " << ref.a << endl;
    return;
}    

int main()
{   
    BASE* bPtr = new BASE(100,100);
    DERIVED* dPtr = new DERIVED(20,20);
    OTHER* oPtr = new OTHER();
    // oPtr->privateAccess(*(bPtr));
    cout << "Derived " << dPtr->B << endl;
    cout << "Base "<< dPtr->b << endl;
    delete bPtr;
    delete dPtr;
    delete oPtr;
    return 0;
}