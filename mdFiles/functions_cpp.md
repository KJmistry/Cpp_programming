# Functions in C++

## Default Arguments in C++

A default argument is a value provided in a function declaration that is automatically assigned by the compiler if the calling function doesn’t provide a value for the argument. In case any value is passed, the default value is overridden.

Example:
``` c++
// CPP Program to demonstrate Default Arguments
#include <iostream>
using namespace std;

// A function with default arguments, it can be called with 2 arguments or 3 arguments or 4 arguments.
int sum(int x, int y, int z = 0, int w = 0) //assigning default values to z,w as 0
{
    return (x + y + z + w);
}

int main()
{
    cout << sum(10, 15) << endl;
    cout << sum(10, 15, 25) << endl;
    cout << sum(10, 15, 25, 30) << endl;
    return 0;
}
```

If function overloading is done containing the default arguments, then we need to make sure it is not ambiguous to the compiler, otherwise it will throw an error.

__Key Points:__  

- Default arguments are different from constant arguments as constant arguments can’t be changed whereas default arguments can be overwritten if required.
- Default arguments are overwritten when the calling function provides values for them. For example, calling the function sum(10, 15, 25, 30) overwrites the values of z and w to 25 and 30 respectively.
- When a function is called, the arguments are copied from the calling function to the called function in the order left to right. Therefore, sum(10, 15, 25) will assign 10, 15, and 25 to x, y, and z respectively, which means that only the default value of w is used.
- Once a default value is used for an argument in the function definition, all subsequent arguments to it must have a default value as well. It can also be stated that the default arguments are assigned from right to left.

For example, the following function definition is invalid as the subsequent argument of the default variable z is not default.
```
    int sum(int x, int y, int z = 0, int w)
```

__Advantages of Default Arguments:__

- Default arguments are useful when we want to increase the capabilities of an existing function.
- It helps in reducing the size of a program. (simple and effective programming approach)
- Default arguments improve the consistency of a program.

__Disadvantages of Default Arguments:__

- It increases the execution time as the compiler needs to replace the omitted arguments by their default values in the function call.

## Inline functions in C++

C++ provides inline functions to reduce the function call overhead. When the inline function is called whole code of the inline function gets inserted at the point of the inline function call. This substitution is performed by the C++ compiler at compile time.  
*__*An inline function may increase efficiency if it is small.__*

Syntax:

    inline return-type function-name(parameters)
    {
        // function code
    }

Remember, inlining is only a request to the compiler, not a command.The compiler may not perform inlining in such circumstances as:

- If a function contains a loop. (for, while and do-while)
- If a function contains static variables.
- If a function is recursive.
- If a function return type is other than void, and the return statement doesn’t exist in a function body.
- If a function contains a switch or goto statement.
  
If the execution time of the function is less than the switching time make function inline.

__Inline function and classes:__

It is also possible to define the inline function inside the class. In fact, all the functions defined inside the class are implicitly inline. Thus, all the restrictions of inline functions are also applied here. If you need to explicitly declare an inline function in the class then just declare the function inside the class and define it outside the class using the inline keyword.

Example:

    class student
    {
    public:
        int square(int s);      // declare the function
    };

    inline int student::square(int s) // use inline prefix
    {

    }

No need to write inline if the function defination is inside class.

__What is wrong with the macro?__

- It is recommended to always use the inline function instead of the macro.
- Macros are error-prone.
- Macro cannot access private members of the class. Macros look like function calls but they are actually not. 

## Return From Void Functions in C++

Void functions are known as Non-Value Returning functions. Void functions do not have a return type, but they can do return values.  

Example:

1. __A Void Function Can Return:__ We can simply write a return statement in a void fun(). In fact, it is considered a good practice (for readability of code) to write a return; statement to indicate the end of the function.
2. __A void fun() can return another void function:__ A void function can also call another void function while it is terminating.

``` c++
// C++ code to demonstrate void() returning void()
#include <iostream>
using namespace std;

void work()           // A sample void function
{
    cout << "The void function has returned a void() !!! \n";
}

void test()
{
    return work();    // Returning void function
}

int main()
{
    test();
    return 0;
}
```

3. __A void() can return a void value:__ A void() cannot return a value that can be used. But it can return a value that is void without giving an error.

``` c++
// C++ code to demonstrate void() returning a void value
#include <iostream>
using namespace std;

void test()
{
    cout << "Hello";
    return (void)"Doesn't Print";  // Returning a void value
}
int main()
{
    test();
    return 0;
}
```

## std::tuple, std::pair | Returning multiple values from a function using Tuple and Pair in C++

One method to do the same is by using pointers, structures or global variables. There is an alternative to achieve same by using tuples (for returning multiple values) and pairs (for two values).

We can declare the function with return type as pair or tuple (whichever is required) and can pack the values to be returned and return the packed set of values. The returned values can be unpacked in the calling function.

__Tuple:__

- A tuple is an object capable to hold a collection of elements where each element can be of a different type.
- Class template std::tuple is a fixed-size collection of heterogeneous values

__Pair:__

- This class couples together a pair of values, which may be of different types
- A pair is a specific case of a std::tuple with two elements

Refer [tuple.cpp](../tuple.cpp) code.

Note:

    In C++, func() is equivalent to func(void)
    In C, func() is equivalent to func(…)

__---------------Remaining From Fuctors----------------__