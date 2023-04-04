/*-----------------Uncomment any one of the following defines to make .exe---------------*/

#define _VIRTUAL_DESTRUCT
// #define _DESTRUCTOR_TRICKY_CODE
// #define _NORMAL_CODE

#ifdef _DESTRUCTOR_TRICKY_CODE
#include <iostream>
using namespace std;
  
int i;
  
class A
{
public:
    ~A()
    {
        i=10;
    }
};
  
int foo()
{
    i=3;
    A ob;
    return i;
}
  
int main()
{
    cout << foo() << endl;
    return 0;
}
#endif

#ifdef _NORMAL_CODE

// Example:

#include<iostream>
using namespace std;
int count=0;
class Test
{
	public:
		Test()
		{
			count++;
			cout<<"\n No. of Object created:\t"<<count;
		}
		
		~Test()
		{
			cout<<"\n No. of Object destroyed:\t"<<count;
			--count;
		}
};

main()
{
	Test t,t1,t2,t3;
	return 0;
}

#endif

#ifdef _VIRTUAL_DESTRUCT
// CPP program without virtual destructor results undefined behavior
#include <iostream>

using namespace std;

class base 
{
public:
	base()	
	{ cout << "Constructing base\n"; }
	virtual ~base()
	{ cout<< "Destructing base\n"; }	
};

class derived: public base 
{
public:
	derived()	
	{ cout << "Constructing derived\n"; }
	~derived()
	{ cout << "Destructing derived\n"; }
};

int main()
{
    derived *d = new derived();
    base *b = d;
    delete b;
    // getchar();
    return 0;
}

#endif