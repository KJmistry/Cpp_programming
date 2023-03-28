# Array and String in C++

## String class

## Raw String Literal in C++

A raw string literal is a string in which the escape characters like ‘ \n, \t, or \” ‘ of C++ are not processed.

Syntex:

    R "delimiter( raw_characters )delimiter" // delimiter is the end of logical entity

delimiter is optional and it can be a character except the backslash{ / }, whitespaces{  }, and parentheses { () }.

## Converting Numbers to String in C++

- Using string Stream
- Using to_string()
- Using boost lexical cast

## Tokenizing a string in C++ (Splitting a string)

Tokenizing a string denotes splitting a string with respect to some delimiter(s). There are many ways to tokenize a string.  
cpp code : Refer [splitting_String.cpp](../splitting_String.cpp)

## getline() Function in C++

The C++ getline() is a standard library function that is used to read a string or a line from an input stream. It is a part of the <string> header.The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered.  

In C++, stream classes support line-oriented functions, getline() and write() to perform input and output functions respectively.

Syntex:

    cin.getline(char*, int size, char='\n')                  // (buffer, stream_size, delimiter) By default delimiter = '\n' 
    getline (istream& is, string& str, char delimiting);     // (inputfrom, buffer to store, delimiter)

## Convert String to Char Array in C++

resolves errors like :  __‘cannot convert std::string to char[] or char* data type’__

__Using c_str() with strcpy():__ (copy the contents of the string to the char array.)

- The c_str() function is used to return a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string.

```c++
// C++ program to convert string to char array using c_str()
#include <cstring>
#include <string>
#include <iostream>

// driver code
int main()
{
    // assigning value to string s
    std::string s = "string";
    const int length = s.length();

    // declaring character array (+1 for null terminator)
    char* char_array = new char[length + 1];

    // copying the contents of the string to char array
    strcpy(char_array, s.c_str());

    /* After utilizing dybamically allocated array*/
    delete[] char_array;
    return 0;
}
```

__Using c_str() without strcpy():__

``` c++
// C++ program to convert string to char array Using c_str() without strcpy()
int main()
{
    // assigning value to string s
    std::string s = "string";

    // the c_str() function returns a const pointer to null terminated contents.
    const char* str = s.c_str();
}

```

## C++ string class and its applications

Refer [strings.cpp](../strings.cpp) code.

For string, there is no need to specify the size and to allocate fixed memory at the time of declaration.

Refer [strings_2.cpp](../strings.cpp) code.

1. compare(string_to_compare):
It is used to compare two strings. It returns the difference between the second string and the first string in the integer.

2. find(“string”):
Searches the string for the first occurrence of the substring specified in arguments. It returns the position of the first occurrence of substring.

3. find_first_of(“string”):
Searches the string for the first character that matches any of the characters specified in its arguments. It returns the position of the first character that matches.

4. find_last_of(“string”):
Searches the string for the last character that matches any of the characters specified in its arguments. It returns the position of the last character that matches.

5. rfind(“string”):
Searches the string for the last occurrence of the substring specified in arguments. It returns the position of the last occurrence of a substring

6. insert(pos_to_begin,string_to_insert):
This function inserts the given substring in the string. It takes two arguments, first the position from which you want to insert the substring and second the substring.

7. clear():
This function clears all the characters from the string. The string becomes empty (length becomes 0) after this operation.

8. empty():
Tests whether the string is empty. This function returns a Boolean value.

## How to Create a Dynamic 2D Array Inside a Class in C++?

A dynamic array is an array that can grow, resize itself, contains a dynamic table, which is mutable in nature, or an array list is randomly accessible, the variable-size list data structure that allows elements to be added or removed.

Refer [2D_array_using_class.cpp](../2D_array_using_class.cpp) code.

## char* vs std:string vs char[] in C++

__1. Using char*:__

str is basically a pointer to the (const)string literal.  
Syntax:

    char* str = "This is string";               // C

- Only one pointer is required to refer to whole string. That shows this is memory efficient.
- No need to declare the size of string beforehand.
- In C string literals are arrays of char but in C++ they are constant array of char. Therefore use const keyword before char*.  

Synex:

    const char* str = "This is string";         // C++

- We cannot modify the string at later stage in program. We can change str to point something else but cannot change value present at str.

__2. Using std::string:__

Syntex:

    std::string str = "This is String";

- Here str is the object of std::string class which is an instantiation of the basic_string class template that uses char (i.e., bytes) as its character type.

[ __Note:__ Do not use cstring or string.h functions when you are declaring string with std::string keyword because std::string strings are of basic_string class type and cstring strings are of const char* type. ]

- When dealing exclusively in C++ std:string is the best way to go because of better searching, replacement, and manipulation functions.

__Cases where you might prefer char* over std:string:__

- When dealing with lower level access like talking to the OS, but usually, if you’re passing the string to the OS then std::string::c_str has it covered.
- Compatibility with old C code (although std::string’s c_str() method handles most of this).
- To conserve memory (std::string will likely have more overhead).

__3. Using char[]:__

Syntex:

    char str[] = "This is GeeksForGeeks";

- We can modify the string at later stage in program.
- This is statically allocated sized array which consumes space in the stack.
- We need to take the large size of array if we want to concatenate or manipulate with other strings since the size of string is fixed. We can use C++ standard library cstring or string.h for that purpose.

## stringstream in C++

A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input.

Basic methods are:

- clear() : To clear the stream.
- str() : To get and set string object whose content is present in the stream.
- operator << : Add a string to the stringstream object.
- operator >> : Read something from the stringstream object.

## Why strcpy and strncpy are not safe to use?

- The strcpy() function does not specify the size of the destination array, so buffer overrun is often a risk.
- If there is no null character among the first n character of src, the string placed in dest will not be null-terminated. So strncpy() does not guarantee that the destination string will be NULL terminated. (strlen() non-terminated string can cause segfault.)

__function that guarantees the destination string will be NULL-terminated and no chance of buffer overrun:__

__snprintf__ and __strlcpy__

Both functions guarantee that the destination string will be NULL terminated.

    strcpy < strncpy < snprintf < strlcpy
