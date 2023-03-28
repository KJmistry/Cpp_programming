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

__delete operator:__

To deallocate dynamically allocated memory.

Syntex:

    delete pointer-variable;

To free the dynamically allocated array pointed by pointer variable, use the following form of delete:

    delete[] pointer-variable;

``` c++
    //Example
    delete[] p;     // It will free the entire array pointed by p.

```

This operator calls the destructor after it destroys the allocated memory also It is faster than free(). free() function only frees the memory from the heap. It does not call the destructor and comparatively slower than delete as it is a function.

## Type casting operators

C++ supports following 4 types of casting operators:

1. const_cast
2. static_cast
3. dynamic_cast
4. reinterpret_cast

__const_cast:__

const_cast is used to cast away the constness of variables.

- const_cast can be used to change non-const class members inside a const member function.
- const_cast can be used to pass const data to a function that doesn’t receive const.
- const_cast is considered safer than simple type casting. It’safer in the sense that the casting won’t happen if the type of cast is not same as original object.
  
__Examples Remaining__