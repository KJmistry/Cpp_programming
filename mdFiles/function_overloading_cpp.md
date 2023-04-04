# Function Overloading

Function overloading is a feature of object-oriented programming where two or more functions can have the same name but different parameters.

## Functions that can not be overloaded

- Function declarations that differ only in the return type.  
[Function overloading comes under the compile-time polymorphism. During compilation, the function signature is checked. So, functions can be overloaded, if the signatures are not the same. The return type of a function has no effect on function overloading]  
- Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration.
- Parameter declarations that differ only in a pointer * versus an array [] are equivalent.
- Parameter declarations that differ only in that, __"one is a function type"__ and the other is __"a pointer to the same function type"__ are equivalent.
- Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent.  
[__*NOTE:__ C++ allows functions to be overloaded on the basis of the const-ness of parameters only if the const parameter is a reference or a pointer.]
- Two parameter declarations that differ only in their default arguments are equivalent.

C++ allows member methods to be overloaded on the basis of const type. Overloading on the basis of const type can be useful when a function returns a reference or pointer.

Refer example[Function Overloading.](../function_overloading.cpp)

## Function overloading with Inheritance

Overloading doesn’t work for derived class in the C++ programming language. There is no overload resolution between Base and Derived.

Refer example[Function Overloading with inheritance.](../function_overloading_inheritance.cpp)

## Overloading main()

- Can not be directly overloaded.  
To overload main() function in C++, it is necessary to use class and declare the main as member function.  
__NOTE:__ main is not reserved word in programming languages like C, C++, Java and C#. can be declared as a variable !

Example for overloading main using class. [Overloading main](../overloading_main.cpp)

## Overloading ambiguity with float

```c++
#include<iostream>
using namespace std;
void test(float s,float t)
{
    cout << "Function with float called ";
}
void test(int s, int t)
{
    cout << "Function with int called ";
}
int main()
{
    test(3.5, 5.6);
    return 0;
}
```

```
error: call of overloaded 'test(double, double)' is ambiguous test(3.5,5.6);
```

As per C++ standard, floating point literals (compile time constants) are treated as double unless explicitly specified by a suffix.Since compiler could not find a function with double argument and got confused if the value should be converted from double to int or float. [solution : test(3.5f, 5.6f);]
