/*
                                          ** Grand Child 1 
                          *** Child 1 *** 
                        *                 ** Grand Child 2
        Parent ****** *
                        *                 ** Grand Child 3
                          *** child 2 ***
                                          ** Grand Child 4
*/
#include <iostream>

using namespace std;

class parent
{
    int a = 10;

protected:
    
    void printParent()
    {
        cout << "Parent called" << endl;
        cout << "Member of parent : " << a << endl;
    }
};

class child1 : public parent
{

protected:
    void printChild()
    {   
        cout << "child 1 called" << endl;
        printParent();
    }
};

class child2 : public parent
{

protected:
    void printChild()
    {   
        cout << "child 2 called" << endl;
        printParent();
    }
};

class Grand_Child1 : public child1
{
public:
    void print()
    {   
        cout << "Grand child 1 called" << endl;
        printChild();
    }
};

class Grand_Child2 : public child1
{
public:
    void print()
    {
        cout << "Grand child 1 called" << endl;
        printChild();
    }
};
int main()
{
    Grand_Child1 obj;            
    obj.print();
}