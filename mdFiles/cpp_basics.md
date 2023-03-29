# C++ Basics

- useful while writing fast Code that also performs well
- Direct access to hardware ! (ex. Game engines are written in cpp)
- In other languages like C# Java run on Virtual Machine (First compiled in to Intermediate Lang. first, while running VM will convert it into machine Lang.at RunTime)
  
# How C++ Works?

- starts with # preprocessor statement !
- __include__ finds file specified and paste content into current program.
- main function --> Entry Point (By default returns 0)
- stages: Preprocessor -> Conpiler(.s) -> assembler(.o) -> linker(final .exe)

# Operators

## Arithmetic Operators (Binary and Unary)
## Relational Operators
## Bit wise Operators
## Logical Operators
## Assignment Operators

# Loops

## for, While, Do While

## Compile program with 32-bit gcc on 64 bit gcc

To check gcc version:

    g++ -v

Now in order to compile with 32-bit gcc, just add a flag -m32 in the command line of compiling the ‘C’ language program.

    g++  -m32 main.c -o main

## Functions

## Arrays

## Strings in Cpp

In Cpp we can store string like C (using char arr) and also using string class (Cpp only).

- String class is a part of C++ library
- Internally uses characer array
- memory management, allocation, and null termination is handled by string class itself
- length of the C++ string can be changed at runtime (due to DMA)

valid string oprations in cpp:

``` cpp
string str1("first string");        // initialization by raw string

string str2(str1);                  // initialization by another string

string str3(5, '#');                // initialization by character with number of occurrence

/** initialization by part of another string **/

string str4(str1, 6, 6);            // from 6th index (second parameter)
                                    // 6 characters (third parameter)

string str5(str2.begin(), str2.begin() + 5);    // initialization by part of another string : iterator version

string str6 = str4;                 // assignment operator

str4.clear();                       // clear function deletes all character from string

/**  both size() and length() return length of string and they work as synonyms **/
int len = str6.length();            // Same as "len = str6.size();"

/** a particular character can be accessed using at [] operator **/
char ch = str6.at(2);               //  Same as "ch = str6[2];

const char* charstr = str6.c_str(); // c_str returns null terminated char array version of string

/** append add the argument string at the end **/
str6.append(" extension");  /*OR*/  str6 += " extension";

/** append part of string **/
str4.append(str6, 0, 6);            // at 0th position 6 character

/**  substr(a, b) function returns a substring of b length starting from index a **/
cout << str6.substr(7, 3) << endl;
 
/** if second argument is not passed, string till end is taken as substring **/

/**  erase(a, b) deletes b characters at index a **/
str6.erase(1, 2);                   // ex. string = abcdef --> output = adef

/**  replace(a, b, str)  replaces b characters from a index by str **/
str6.replace(2, 7, "string");

/* if length of string is lesser than the chacters to be replaced
   it will replace with all given character and will skip remaining index
   i.e. --> str6 = abcdefgh 
            str6.replace(2, 5, "aaa");
            
            result = "abaaah"
```

Find matching substring with in a string if available

``` cpp

/**  find returns index where pattern is found.
    If pattern is not there it returns predefined constant npos whose value is -1 **/
 
    if (str6.find(str4) != string::npos)
        cout << "str4 found in str6 at " << str6.find(str4)
             << " pos" << endl;
    else
        cout << "str4 not found in str6" << endl;

```

## Pointers

### Use of Pointers

- Pass Arguments by Reference
- Accessing Array Elements
- Return Multiple Values from Function
- Dynamic Memory Allocation
- Implementing Data Structures
- In System-Level Programming where memory addresses are useful.
- In locating the exact value at some memory location.
- To avoid compiler confusion for the same variable name.
- To use in Control Tables.

## References in C++

- When a variable is declared as a reference, it becomes an alternative name for an existing variable.
- A variable can be declared as a reference by putting ‘&’ in the declaration.
- Variables associated with reference variables can be accessed either by its name or by the reference variable associated with it.

syntax:

    data_type &ref = variable;

example:
``` c++
    int x = 10;  
    int& ref = x;               // ref is a reference to x  
    ref = 20;                   // Value of x is now changed to 20
    x = 30;                     // Value of x is now changed to 30
```