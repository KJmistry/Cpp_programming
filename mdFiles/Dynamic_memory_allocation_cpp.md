# Dynamic memory allocation in C++

## new and delete operator in C++

C uses the malloc() and calloc() function to allocate memory dynamically free() to free the allocated memory.  
C++ supports these functions and also has two operators new and delete, that perform the task of allocating and freeing the memory in a better and easier way.

__new operator:__

The new operator denotes a request for memory allocation on the Free Store. If sufficient memory is available, a new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable.

syntax:

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

Syntax:

    pointer-variable = new data-type(value);

__Allocate a block of memory:__ a new operator is also used to allocate a block(an array) of memory of type data type.

Syntax:

    pointer-variable = new data-type[size];

__If enough memory is not available during runtime:__  
If enough memory is not available in the heap to allocate, the new request indicates failure by throwing an exception of type std::bad_alloc, unless “nothrow” is used with the new operator, in which case it returns a NULL pointer.

``` c++
int *p = new(nothrow) int;
if (!p)
{
   cout << "Memory allocation failed\n";
}
```

__delete operator:__

To deallocate dynamically allocated memory.

Syntax:

    delete pointer-variable;

To free the dynamically allocated array pointed by pointer variable, use the following form of delete:

    delete[] pointer-variable;

``` c++
    //Example
    delete[] p;     // It will free the entire array pointed by p.

```

This operator calls the destructor after it destroys the allocated memory also It is faster than free(). free() function only frees the memory from the heap. It does not call the destructor and comparatively slower than delete as it is a function.

## new vs malloc

- new calls constructors, while malloc() does not. In fact primitive data types (char, int, float.. etc) can also be initialized with new.
- new is an operator, while malloc() is a function.
- new returns exact data type, while malloc() returns void *.
- On failure, malloc() returns NULL where as new throws bad_alloc exception.
- In case of new, memory is allocated from free store where as in malloc() memory allocation is done from heap.
- malloc() allows to change the size of buffer using realloc() while new doesn’t.

## std::get_temporary_buffer in C++

Get a block of temporary memory. In C++ STL library, there is a function get_temporary_buffer which is mostly used to get a temporary block. Used to get a memory of temporary nature mostly used for the operation of an algorithm as some algorithms required extra space to perform correctly. Released by calling return_temporary_buffer.

Syntax:

    pair(int*, ptrdiff_t) p = get_temporary_buffer(int)(required size)

Parameters:

- n: Number of elements of type T for which temporary memory is allocated.
- ptrdiff_t: it is an integral type.

Return:  
The function returns the first and second pair of objects. When memory is allocated the first contains the pointer to the first element in the block and the second contains the size. If the memory block is not allocated than the first pair contains null pointer and second contains zero.
