# Scope Resolution Operator vs this pointer in C++

## Scope resolution operator(::) is for accessing static or class members  

- To access a global variable when there is a local variable with same name
- To define a function outside a class.
- To access a class’s static variables.
- In case of multiple Inheritance: If the same variable name exists in two ancestor classes, we can use scope resolution operator to distinguish.
- For namespace If a class having the same name exists inside two namespaces we can use the namespace name with the scope resolution operator to refer that class without any conflicts
- Refer to a class inside another class: If a class exists inside another class we can use the nesting class to refer the nested class using the scope resolution operator

## this pointer is for accessing object members when there is a local variable with the same name.

- to access(i.e print) class's variable instead of local variable of member function of the class.  
    __cout << this->variable_name;__

## new and delete Operators in C++ For Dynamic Memory

Operators new and delete, that perform the task of allocating and freeing the memory in a better and easier way.

__new operator__:

The new operator denotes a request for memory allocation on the Free Store. If sufficient memory is available, a new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable.

syntex:

    pointer-variable = new data-type;

Here, the pointer variable is the pointer of type data-type. Data type could be any built-in data type including array or any user-defined data type including structure and class.

Example:
``` c++
int *p = NULL; 
p = new int;  

/*OR*/

int *p = new int; 
```

__Initialize memory:__ We can also initialize the memory for built-in data types using a new operator. For custom data types, a constructor is required (with the data type as input) for initializing the value.

Syntex:

    pointer-variable = new data-type(value);

__Allocate a block of memory:__ a new operator is also used to allocate a block(an array) of memory of type data type.

Syntex:

    pointer-variable = new data-type[size];

__delere operator:__

To deallocate dynamically allocated memory.

Syntex:

    delete pointer-variable;

To free the dynamically allocated array pointed by pointer variable, use the following form of delete:

    delete[] pointer-variable;

``` c++
    //Example
    delete[] p;     // It will free the entire array pointed by p.

```

