# Pointers

## Array Decay in C++

The loss of type and dimensions of an array is known as decay of an array.This generally occurs when we pass the array into function by value or pointer.

Solution:

- A typical solution to handle decay is to pass size of array also as a parameter and not use sizeof on array parameters.
- Another way to prevent array decay is to send the array into functions by reference.
  
## Opaque Pointer in C++

Opaque as the name suggests is something we can’t see through. An opaque pointer is a pointer that points to a data structure whose contents are not exposed at the time of its definition.

i.e: structure pointer, One can’t know the data contained in structure just by looking at the definition.

__Why Opaque pointer?__

There are places where we just want to hint to the compiler some data structure that will be used by clients. Clients will provide its implementation while preparing the compilation unit. Such type of design is robust when we deal with shared code.

## Smart Pointers in C++

Pointers are used for accessing the resources which are external to the program – like heap memory. So, for accessing the heap memory (if anything is created inside heap memory), pointers are used. If we use a pointer to the resource, we’ll be able to change the original resource instead of copy of it.

__Problems with Normal Pointers__

- Memory Leaks: memory is allocated but never freed.
- Dangling Pointers: The object which is pointeed by pointer nd is de-allocated from memory.
- Wild Pointers: pointer is never initialized to point to any valid object or address.
- Data Inconsistency: Data inconsistency occurs when some data is stored in memory but is not updated in a consistent manner.
- Buffer Overflow: When a pointer is used to write data to a memory address that is outside of the allocated memory block.

Not deallocating a pointer causes a memory leak. Using smart pointers programmer doesn’t have to worry about any memory leaks. When the object is destroyed it frees the memory as well.

A Smart Pointer is a wrapper class over a pointer with an operator like * and -> overloaded. The objects of the smart pointer class look like normal pointers. But, unlike Normal Pointers it can deallocate and free destroyed object memory. The idea is to take a class with a pointer, destructor, and overloaded operators like * and ->.

[Refer [smart_pointer.cpp](../smart_pointer.cpp) code]

Since the destructor is automatically called when an object goes out of scope, the dynamically allocated memory would automatically be deleted.

__Types of Smart Pointers:__

- auto_ptr
- unique_ptr
- shared_ptr
- weak_ptr

__[Programs remaining (c++ template)]__

## 'this' Pointer in c++
 
Each object gets its own copy of data members and all objects share a single copy of member functions.

The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions.

‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).

__Actual defination of this pointer :__ pointer of type class
example:
```
class entity {};

entity* ptr = this;
```

__C++ lets object destroy themselves by calling the following code:__

    delete this;

__Situations where ‘this’ pointer is used:__

1) When local variable’s name is same as member’s name
2) To return reference to the calling object

[Refer [this_pointer.cpp](../this_pointer.cpp) code]

## Type of ‘this’ pointer

The type of this depends upon function declaration. The type of this pointer is either 'const className*' or 'className*'. It depends on whether it lies inside a const or a non-const method of the class className.

__1) Const ExampleClass:__
If the member function of class X is declared const, the type of this is const X*

``` c++
// C++ Program to demonstrate if the member function of a class X is declared const
#include <iostream>
using namespace std;

class X {
    void fun() const
    {
        // this is passed as hidden argument to fun().
        // Type of this is const X* const
    }
};
```

__2) Non-Const ExampleClass:__
If the member function is declared volatile, the type of this is volatile X*

``` c++
// C++ Program to demonstrate if the member function is declared volatile
#include <iostream>
using namespace std;

class X {
    void fun() volatile
    {
    // this is passed as hidden argument to fun().
    // Type of this is volatile X* const
    }
};
```

## "Delete this"

1) delete operator works only for objects allocated using operator new. If the object is created using new, then we can do delete this, otherwise behavior is undefined.
2) Once delete this is done, any member of the deleted object should not be accessed after deletion.

``` c++
    /*A member function of any class*/
    void fun() 
    {
        delete this;
        /* Invalid: Undefined Behavior */
        cout << "hello";    // this is working
    }
```

## Understanding nullptr in C++

NULL is typically defined as (void *)0 and conversion of NULL to integral types is allowed.  
nullptr is a keyword that can be used at all places where NULL is expected.

- Like NULL, nullptr is implicitly convertible and comparable to any pointer type.
- Unlike NULL, it is not implicitly convertible or comparable to integral types.

``` c++  
    int* x = nullptr; // valid
    int* x = NULL;    // valid
    int x = NULL;     // valid
    int x = nullptr;  // invalid
```

# References

When a variable is declared as a reference, it becomes an alternative name for an existing variable. A variable can be declared as a reference by putting ‘&’ in the declaration.

Also, we can define a reference variable as a type of variable that can act as a reference to another variable. ‘&’ is used for signifying the address of a variable or any memory. Variables associated with reference variables can be accessed either by its name or by the reference variable associated with it.

Syntax:

    data_type &ref = variable;

example:

``` c++
    int x = 10;  
    int& ref = x;               // ref is a reference to x  
    ref = 20;                   // Value of x is now changed to 20
    x = 30;                     // Value of x is now changed to 30
```

## Application of Reference in Cpp

- Modify the passed parameters in a function [Refer [reference_modify_val.cpp](../reference_modify_val.cpp) code]
- Avoiding a copy of large structures (if we pass without reference the new copy will be creared) [Refer [reference_structure.cpp](../reference_structure.cpp) code]
- In For Each Loop to modify all objects [Refer [reference_loop_modify_obj.cpp](../reference_loop_modify_obj.cpp) code]
- For Each Loop to avoid the copy of objects [Refer [reference_loop_modify_obj.cpp](../reference_loop_modify_obj.cpp) code]
- function can be accessed using references [Refer [reference_function.cpp](../reference_function.cpp) code]

## Difference Between Reference and Pointer

- A pointer can be declared as void but a reference can never be void For example
- The pointer variable has n-levels/multiple levels of indirection i.e. single-pointer, double-pointer, triple-pointer. Whereas, the reference variable has only one/single level of indirection.
- Reference variables cannot be updated.
- Reference variable is an internal pointer. 
  (Since it can access the same memory location** as the variable of which it is a reference, a reference variable is internally implemented as a pointer.)
- Declaration of a Reference variable is preceded with the ‘&’ symbol __(***but do not read it as “address of”)__.

__Which is preferred, Passing by Pointer Vs Passing by Reference in C++?__

- References are usually preferred over pointers whenever we don’t need “reseating”.
- If we want to use NULL in our function arguments, prefer pointers.
- Overall, Use references when you can, and pointers when you have to.

## Limitations of References

- Once a reference is created, it cannot be later made to reference another object; it cannot be reset. This is often done with pointers.
- References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
- A reference must be initialized when declared. There is no such restriction with pointers.

Due to the above limitations, references in C++ cannot be used for implementing data structures like Linked List, Tree, etc.

## Advatanges of using Reference Variables

__Safer__: Since references must be initialized, wild references like wild pointers are unlikely to exist.  
__Easier to use__: References don’t need a dereferencing operator to access the value. Members of an object reference can be accessed with the dot operator (‘.’), unlike pointers where the arrow operator (->) is needed.

## References Refer to Invalid Location in C++

1) Reference to Value at the Uninitialized Pointer:

``` c++
    int *ptr;
    int &ref = *ptr; // Reference to value at some random memory location
```

2) Reference to a Local Variable is Returned:

``` c++
    int& fun()
    {
        int a = 10;
        return a;
    }    
```

## When do we pass arguments by reference(or pointer)?

1) To modify local variables of the caller function:

``` c++
    void fun(int& x) 
    { 
        x = 20; 
    }
    int main()
    {   
        int x = 10;
        fun(x);
    }
```

1) For passing large sized arguments: (Pass struct or class using reference to avoid copy of the same)
2) To avoid Object Slicing:

   If we pass an object of subclass to a function that expects an object of superclass then the passed object is sliced if it is pass by value. [Refer [pass_by_reference_class_object.cpp](../pass_by_reference_class_object.cpp) code]

3) To achieve Run Time Polymorphism in a function:

   We can make a function polymorphic by passing objects as reference (or pointer) to it. [Refer [runtime_polymorphism_using_reference.cpp](../runtime_polymorphism_using_reference.cpp) code]
