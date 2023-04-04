#include<iostream>

using namespace std;

#define _CODE_2

#ifdef _CODE_1

class theClass 
{
public:
    string str;
    int a = 10;    
    int *ptr = &a;

    theClass(){}                                    // always create one default constructor (copy constructor will overwrite default constructor)

    theClass(string tStr)
    {
        str = tStr;
    }                                         

    // theClass(const theClass& refVar)                   // To avoid shallow copy
    // {
    //     a = refVar.a;
    // }

    void init(int temp)
    {
        a = temp;        
    }

};

int main()
{
    theClass object1("string1"),object3("string3");
    theClass object2 = object1;                                     // Calling copy constructor 

    cout << "Object 1 members" << endl;
    
    cout << "&a = " << object1.ptr << endl;
    cout << "a = " << *(object1.ptr) << endl;
    cout << "&ptr = " << &(object1.ptr) << endl;
    cout << "string = " << object1.str << endl;
    

    object1.a = 90;
    object2.str = "string2";

    cout << "Object 2 members" << endl;

    cout << "&a = " << object2.ptr << endl;
    cout << "a = " << *(object2.ptr) << endl;
    cout << "&ptr = " << &(object2.ptr) << endl;
    cout << "string = " << object1.str << endl;

    object3 = object1;                                              // Using assignment operator

    cout << "Object 3 members" << endl;

    cout << "&a = " << object3.ptr << endl;
    cout << "a = " << *(object3.ptr) << endl;
    cout << "&ptr = " << &(object3.ptr) << endl;
    cout << "string = " << object3.str << endl;

}
#endif

#ifdef _CODE_2

#include <cstring>

class String {
private:
	char* s;
	int size;

public:

	String(const char* str = NULL);                                 // constructor

    String(const String&);                                          // copy constructor

	~String()                                                       // destructor
    { 
        delete[] s; 
    }                                       

	void print() 
    { 
        cout << s << endl; 
    }

	void change(const char*);                                       // Function to change
};

String::String(const char* str)
{
	size = strlen(str);
	s = new char[size + 1];
	strcpy(s, str);
}

String::String(const String& old_str)                               // to create deep copy
{
    size = old_str.size;
    s = new char[size + 1];
    strcpy(s, old_str.s);
}

// In this the pointer returns the CHAR ARRAY in the same sequence of string object but with an additional null pointer '\0'

void String::change(const char* str) { strcpy(s, str); }

int main()
{
	String str1("GeeksQuiz");
	String str2 = str1;

	str1.print();                                                   // what is printed ?
	str2.print();

	str2.change("GeeksforGeeks");

	str1.print();                                                   // what is printed now ?
	str2.print();
	return 0;
}

#endif
