#include <iostream>

using namespace std;
class B;
class A 
{
    int a = 10;
    friend void display(A& ,B&);
};

class B 
{
    int b = 20;    
    friend void display(A& ,B&);
};

void display(A& ref_a ,B& ref_b)
{
    cout << "a= "<< ref_a.a << " b= " << ref_b.b << endl; 
}

int main()
{
    A a;
    B b;
    display(a,b);
}
