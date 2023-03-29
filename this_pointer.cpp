#define _USE_CODE_1

#ifdef _USE_CODE_1
#include<iostream>
using namespace std;

/* local variable is same as a member's name */
class Test
{
    private:
        int x = 90;

    public:
    void setX (int x)
    {   
        // The 'this' pointer is used to retrieve the object's x hidden by the local variable 'x'
        Test* ptr = this; 
        // ptr = NULL;
        ptr->x = x;
        cout << "&this = " << ptr << endl;
    }
    
    void print() 
    { 
        cout << "x = " << x << endl; 
    }
};

int main()
{
    Test obj,obj2;
    int x = 20;
    obj.setX(x);
    obj.print();
    return 0;
}
#endif

#ifdef _USE_CODE_2
/*---------------------------------return reference to calling object------------------------------------*/
#include<iostream>
using namespace std;

class Test
{
private:
    int x;
    int y;

public:
    Test(int x = 0, int y = 0) 
    { 
        this->x = x; 
        this->y = y; 
    }
    
    Test& setX(int a) 
    { 
        x = a; 
        return *this; 
    }
    
    Test& setY(int b) 
    { 
        y = b; 
        return *this; 
    }
    
    void print() 
    { 
        cout << "x = " << x << " y = " << y << endl; 
    }
};

int main()
{
    Test obj1(5, 5);

    // Chained function calls. All calls modify the same object as the same object is returned by reference
    obj1.setX(10).setY(20);   // this wont work is we make setX as void setX and remove the return statement
    obj1.print();
    obj1.setX(9);
    obj1.print();
    return 0;
}
#endif
