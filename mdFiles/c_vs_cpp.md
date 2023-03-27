# C vs C++

## C programs that won't compile in C++ even if C++ is having backward compatibility with C

- Calling a function before the declaration
- Using normal pointer with const variable
- Using typecasted pointers
- Declaring constant values without initializing
- Using specific keywords as variable names
- Strict type checking
- The return type of main()
  
## Undefined behavior in C and C++

- Division By Zero
- Memory accesses outside of array bounds
- Signed integer overflow
- Null pointer dereference
- Modification of string literal
- Accessing a NULL Pointer, etc.

## Name Mangling and extern “C” in C++

C++ supports function overloading. How does the C++ compiler distinguish between different functions when it generates object code – it changes names by adding information about arguments. This technique of adding additional information to function names is called Name Mangling.  
(C++ standard doesn’t specify any particular technique for name mangling, so different compilers may append different information to function name)

## How to handle C symbols when linking from C++?

In C, names may not be mangled as it doesn’t support function overloading. So how to make sure that name of a symbol is not changed when we link a C code in C++.  
Example:

``` c++
// C Program to demonstrate it doesn't support Name Mangling
int printf(const char* format, ...);
// Driver Code
int main()
{
    printf("GeeksforGeeks");
    return 0;
}

```

The above code will generate an error, because the name of printf() is changed by the C++ compiler and it doesn’t find the definition of the function with a new name.

__Solution:__

When some code is put in the extern “C” block, the C++ compiler ensures that the function names are un-mangled – that the compiler emits a binary file with their names unchanged, as a C compiler would do.

``` c++
// CPP Program to demonstrate Extern "C"

extern "C" {
int printf(const char* format, ...);
}

// Driver Code
int main()
{
    printf("GeeksforGeeks");
    return 0;
}

```

Therefore, all C style header files (stdio.h, string.h, etc) have their declarations in the extern “C” block.

__Importatnt:__

``` c
/** one of the uses of #ifndef: Inside any library the first statement using ifndef is always present to avoid the errors due to multiple include statements of same library. (generally programmer will not inlude same library multiple times but for ex. along with iostream thread is included but thread library its self is using iostream which indirectly results into multiple definetions). ifndef (#ifndef _GLIBCXX_IOSTREAM) will ensure if it was already included some where. **/
```

## Void pointer in C and C++

C allows a void pointer to be assigned to any pointer type without a cast, whereas in C++, it does not.0 We have to explicitly typecast the void pointer in C++.

``` c++
/*----------------valid in C-----------------*/
void* ptr;
int *i = ptr; // Implicit conversion from void* to int* 

/*----------------valid in C++---------------*/
void* ptr;
int *i = (int *) ptr;
```

## Type Difference of Character Literals in C and C++

- C result – sizeof(‘V’) = 4 and sizeof(char) = 1
- C++ result – sizeof(‘V’) = 1 and sizeof(char) = 1

__C vs C++__  
Only data members are allowed,it cannot have member functions. <------------------>Can hold both: member functions and data members.  
Cannot have a constructor inside a structure.<-------------------------------------------------------------------------->Constructor creation is allowed.  
Direct Initialization of data members is not possible.<--------------------------------------------------------------->Direct Initialization of data members is possible.  
Writing the ‘struct’ keyword is necessary to declare structure-type variables.<--------------------------->Writing the ‘struct’ keyword is not necessary to declare structure-type variables.  
Do not have access modifiers.<------------------------------------------------------------------------------------------------->Supports access modifiers.  
Only pointers to structs are allowed.<-------------------------------------------------------------------------------------->Can have both pointers and references to the struct.  
Sizeof operator will generate 0  for an empty structure.<---------------------------------------------------------->Sizeof operator will generate 1 for an empty structure.  
Data Hiding is not possible.<---------------------------------------------------------------------------------------------------->Data Hiding is possible.  
