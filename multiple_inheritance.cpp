/*
                          *** Parent 1
                        *
        child ******* *
                        *
                          *** Parent 2
*/

#include <iostream>

using namespace std;

class parent1 
{
    int a = 10;

protected:
    
    void printParent()
    {
        cout << "Member of parent 1 : " << a << endl;
    }
};

class parent2 
{
    int b = 20;

protected:
    
    void printParent()
    {
        cout << "Member of parent 2 : " << b << endl;
    }
};

class child : public parent1 , public parent2 
{

// using parent1::printParent;
// using parent2::printParent;

public:
    void print()
    {
        parent1::printParent();
        parent2::printParent();
    }
};

int main()
{
    child obj;
    obj.print();
}