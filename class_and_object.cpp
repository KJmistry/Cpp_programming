#include<iostream>

using namespace std;

class myFirstClass
{
    int member1,member2;
    string member1Name,member2Name;

protected:
    int protectedMemer1,protectedMemer2;

public:

    int publicMember1,publicMember2;

    myFirstClass()                                                                                      // default constructor
    {
        cout << "Default Constructor called !" << endl;
    }
    
    myFirstClass(int val)                                                                               // parameterized constructor  
    {
        cout << "Parameterized Constructor called !" << endl;
    }

    // myFirstClass(myFirstClass& ref)                                                                     // Explicit Copy Constructor
    // {
    //     publicMember1 = ref.publicMember1;
    //     publicMember2 = ref.publicMember2;
    // }

    void assignValue(int a = 0, int b = 0, string str1 = "Default",string str2 = "Default")             // also called method 
    {
        member1 = a;
        member2 = b;
        member1Name = str1;
        member2Name = str2;
        protectedMemer1 = 10;
    }
    void printDetails();

    myFirstClass& assignUsingThis(int a = 0, int b = 0, string str1 = "Default",string str2 = "Default")        // use of this pointer as a return value
    {
        member1 = a;
        member2 = b;
        member1Name = str1;
        member2Name = str2;
        return *this;
    }
};

void myFirstClass::printDetails()
{
    cout << "member1 value :" << member1 << endl;
    cout << "member2 value :" << member2 << endl;
    cout << "public member1 value :" << publicMember1 << endl;
    cout << "public member2 value :" << publicMember2 << endl;
    cout << "member1 Name :" << member1Name << endl;
    cout << "member2 Name :" << member2Name << endl;
}

int main(int argc, char const *argv[])
{
    myFirstClass myFirstObj1(10);                                                                               // Implicit call
    // myFirstClass myFirstObj = myFirstClass(10);                                                              // Explicit call
  

    /*--------------------------------------initilaizing object 1------------------------------------------*/


    myFirstObj1.assignValue(9,9,"Kshitij"); 
    myFirstObj1.publicMember1=99;
    myFirstObj1.publicMember2=99;


    myFirstObj1.printDetails();                                                                                 // printing data of obj1
    
    
    myFirstClass myFirstObj2(myFirstObj1);    /*OR*/    /*---myFirstClass myFirstObj2 = myFirstObj1;---*/       // calling copy constructor by providing ref of obj1  
    myFirstObj2.assignValue(10,10,"Mistry");
    //myFirstObj.assignUsingThis().publicMember1=90;                                                            // use of this                                                       
    myFirstObj2.printDetails();
    myFirstObj1.publicMember2=91;
    myFirstObj2.printDetails();
    myFirstObj1.printDetails();


    return 0;
}
