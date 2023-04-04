# Constructors & Destructors

## Constructors

Constructors are special class members which are called by the compiler every time an object of that class is instantiated. Constructors have the same name as the class and may be defined inside or outside the class definition. Used to initialize the data members for an object of a class automatically.Constructor do not return value, hence they do not have a return type.

- Constructors can be overloaded. (Parameterized constructors)
- Constructor can not be declared virtual.
- It must be placed in public section of class.
- If we do not specify a constructor, C++ compiler generates a default constructor for object (expects no parameters and has an empty body).
- The compiler doesn’t create a default constructor if we write any constructor even if it is a copy constructor.
- The compiler creates a copy constructor if we don’t write our own. The compiler creates it even if we have written other constructors in a class.
- Constructor cannot be inherited.

Refer [Constructors sample program](../constructors.cpp)  
Refer [Virtual Constructors](../virtual_constructor.cpp) (Advance C++)  
Refer [Virtual Copy constructor](../virtual_copy_constructor.cpp) (Advance C++)
Extra code [default constructor](../default_constructor_builtin_datatype.cpp)(builtin data types)  

__Three Types:__

1. Default constructors
2. Parameterized constructors
3. Copy constructors

__Default Constructor:__

Default constructor is the constructor which doesn’t take any argument. It has no parameters. It is also called a zero-argument constructor.

The prototype of the constructor:

    className ();

__Parameterized Constructors:__

 To create a parameterized constructor, simply add parameters to it like functions. Use the parameters to initialize the object while creating.

    className(list-of-parameters);

[Note: when the parameterized constructor is defined and no default constructor is defined explicitly, the compiler will not implicitly call the default constructor and hence creating a simple object(without passing arguments) will throw an error]

Uses of Parameterized constructor:

- It is used to initialize the various data elements of different objects with different values when they are created.
- It is used to overload constructors.

__Copy Constructor:__

A copy constructor is a member function that initializes an object using another object of the same class(__copy initialization__).Copy constructor takes a reference to an object of the same class as an argument.

    className(className& t)
          {
            id=t.id;
          }

Above is an example of explicit(User defined) copy constructor.  
No need to additionaly create implicit copy constructor! while creating object pass another object reference as an argument. properties of old object (passed as a reference) will get copied in to the newly created object.

Refer [copy Constructors vs assignment operator overloading](../copy_constructors_vs_assignment_operator.cpp)  

__Tow types:__

1. Default Copy Constructor  
An implicitly defined copy constructor will copy the bases and members of an object in the same order that a constructor would initialize the bases and members of the object.

1. User defined Copy Constructor  
A user-defined copy constructor is generally needed when an object owns pointers or any runtime allocation of the resource like a file handle, a network connection, etc.(non-shareable references), in which case a destructor and an assignment operator should also be written.

- The default constructor does only shallow copy.
- Deep copy is possible only with a user-defined copy constructor. In a user-defined copy constructor, we make sure that pointers (or references) of copied objects point to new memory locations.  

Copy Elision: In copy elision, the compiler prevents the making of extra copies which results in saving space and better the program complexity.
[For Extra Study: __Return Value Optimization(RVO) & Named Return Value Optimization(NRVO)__ ]

__Making a copy constructor private:__

A copy constructor can be made private, objects of that class become non-copyable. Useful when our class has pointers or dynamically allocated resources. In such situations, we can either write our own copy constructor or make a private copy constructor so that users get compiler errors rather than surprises at runtime.

Refer [Copy Constructors sample program](../copy_constructors.cpp)

Argument to a copy constructor must be passed as a reference. (If we pass an argument by value in a copy constructor, a call to the copy constructor would be made to call the copy constructor which becomes a non-terminating chain of calls.)

__const__ argument to copy constructor: use const in C++ wherever possible so that objects are not accidentally modified.

__Copy constructor vs Assignment Operator:__  
The main difference between Copy Constructor and Assignment Operator is that the Copy constructor makes a new memory storage every time it is called while the assignment operator does not make new memory storage.

## __Use of explicit key word:__

Explicit Keyword in C++ is used to mark constructors to not implicitly convert types in C++.  
Refer [Use of Explicit keyword](../explicit_keyword.cpp)

## __When to use Initializer list in C++__

- For initialization of non-static const data members.

```
static objects are always destroyed at the end of the program whether their scope is local or global. 
```

``` c++
class Test {
    const int t;
public:
    Test(int t) : t(t) 
    {}                      
};
```

- For initialization of reference members.

```c++
class Test {
    int &t;
public:
    Test(int &t):t(t) 
    {}  
};
```

- For initialization of member objects which do not have default constructor.
- For initialization of base class members.
  
```c++
class A {
    int i;
public:
    A(int arg)
    {
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
    }
};

class B: public A {
public:
B(int x):A(x) 
{
    cout << "B's Constructor called";
}
};
```

- When constructor’s parameter name is same as data member For Performance reasons.  
  - if we use assignment inside constructor body there are three function calls: constructor + destructor + one addition assignment operator call  
  - if we use Initializer List there are only two function calls: copy constructor + destructor call

## Destructors

Destructor destroys the class objects created by the constructor.Destructor has the same name as their class name preceded by a tilde (~) symbol.

    ~className() { /*Defination*/ }

- It is not possible to define more than one destructor.
- The destructor is only one way to destroy the object created by the constructor, hence it can't be overloaded.
- Destructor neither requires any argument nor returns any value, automatically called when the object goes out of scope.
- Destructor cannot be declared as static and const.
- Destructor should be declared in the public section of the program.
- Destructor is called in the reverse order of its constructor invocation.
- Destructor can be made private.

__Note:__ destructor can also be called explicitly for an object.

    syntax: 
    object_name.~class_name();

Refer [Destructor sample program](../destructors.cpp)

```
    The functions that are generated by the compiler by default if we do not provide them explicitly are:
    1. Default constructor
    2. Copy constructor
    3. Assignment operator
    4. Destructor
```

__Use of user-defined Destructor:__  
When a class contains a pointer to memory allocated in class, we should write a destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.

__Can a destructor be virtual?__  
Yes, In fact, it is always a good idea to make destructors virtual in base class when we have a virtual function.

Refer [Destructor special case.](../destructor_special_case.cpp)

## __Private Destructors__

To control the destruction of objects of a class, we make the destructor private. Making destructor is valid in cpp, compiler will not generate any error. If we are creating the object of the class having destructor private, at main termination the destructor will be called by compiler and will generate an error since destructor is private.

- Works fine in the cases where we are allocating memory for an object dynamically. since the it is dynamically allocated its programmers task to free the memory, compiler will doesn't bother.
- To call private destructor we can use friend function having delete statement.
- Another way is by writing public member function which can access private members of a class. (delete this inside public function)

Refer [Private Destructor.](../private_destructor.cpp)

## Calling Constructor and Destructor explicitly

- Once a destructor is invoked for an object, the object no longer exists; the behavior is undefined if the destructor is invoked for an object whose lifetime has ended.
- We should never call the destructor explicitly on a local (automatic) object because really bad results can be acquired by doing that.
- Local objects are automatically destroyed by the compiler when they go out of scope.  
Refer [Explicit call.](../explicit_call_constructor_destructor.cpp)
