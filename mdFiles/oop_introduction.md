# Object Oriented Programming in C++

Aims to implement real-world entities like inheritance, hiding, polymorphism, etc. in programming.  
Bind together the data and the functions that operate on them so that no other part of the code can access this data except that function.

## Basic concepts that act as the building blocks of OOPs

- Class
- Objects
- Encapsulation
- Abstraction
- Polymorphism
- Inheritance
- Dynamic Binding
- Message Passing
  
### Class

It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class.
We can say that a Class in C++ is a blueprint representing a group of objects which shares some common properties and behaviors.

(In terms of additional functionalities classes are not providing anything special that can not be achived without using it, they are just for better visibility of code and a modular approach while writing codes having multiple liens)

### Object

An Object is an identifiable entity with some characteristics and behavior. An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.  
Each object contains data and code to manipulate the data.

``` c++
// C++ Program to show the syntax/working of Objects as a
// part of Object Oriented PProgramming
#include <iostream>
using namespace std;

    class person {
        char name[20];
        int id;

    public:
        void getdetails() 
        {
            
        }
    };

    int main()
    {
        person p1; // p1 is a object
        return 0;
    }
```

### Encapsulation

In normal terms, Encapsulation is defined as wrapping up data and information under a single unit.  
In Object-Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.  
Encapsulation also leads to data abstraction or data hiding. Using encapsulation also hides the data from other class objects.

### Abstraction

One of the most essential and important features of object-oriented programming in C++.  
Abstraction means displaying only essential information and hiding the details.(Providing only essential information about the data to the outside world)

__Abstraction Using Class:__ The class helps us to group data members and member functions using available access specifiers. A Class can decide which data member will be visible to the outside world and which is not.

__Abstraction in Header files:__ One more type of abstraction in C++ can be header files.

### Polymorphism

Polymorphism means having many forms.  
An operation may exhibit different behaviors in different instances. The behavior depends upon the types of data used in the operation. C++ supports operator overloading and function overloading.

__Operator Overloading:__ The process of making an operator exhibit different behaviors in different instances is known as operator overloading.  
__Function Overloading:__ Function overloading is using a single function name to perform different types of tasks. Polymorphism is extensively used in implementing inheritance.

### Inheritance

The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important features of Object-Oriented Programming.

__Sub Class:__ The class that inherits properties from another class is called Sub class or Derived Class.  
__Super Class:__ The class whose properties are inherited by a sub-class is called Base Class or Superclass.  
__Reusability:__ Inheritance supports the concept of “reusability”,  
i.e. when we want to create a new class and there is already a class that includes some of the code that we want, we can derive our new class from the existing class. By doing this, we are reusing the fields and methods of the existing class.  

### Dynamic Binding

In dynamic binding, the code to be executed in response to the function call is decided at runtime. C++ has virtual functions to support this. Because dynamic binding is flexible, it avoids the drawbacks of static binding, which connected the function call and definition at build time.  

Ex. Two class one base and another derived, print function availabe in both.  
After creating two objects (one of base and another of derived) calling print function with base and derived class object.  
both time the function from base class will get executed.  
To resolve this problem virtual classes are used.

### Message Passing

Objects communicate with one another by sending and receiving information. A message for an object is a request for the execution of a procedure and therefore will invoke a function in the receiving object that generates the desired results. Message passing involves specifying the name of the object, the name of the function, and the information to be sent.
