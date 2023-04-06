# Virtual Functions

A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class.

- It tells the compiler to perform late binding where the compiler matches the object with the right called function and executes it during the runtime.(Runtime Polymorphism)
- In C++ what calling a virtual function means, calling a function depending on the type of object.

__NOTE:__
```
Because overriding from derived classes hasn’t happened yet, the virtual call mechanism is disallowed in constructors. Also to mention that objects are built from the ground up or follows a bottom to top approach.
```

If we do not declare overridden function as virtual inside the base class, the resulting call of the function will alwaya be of base class(class pointer type).     This happens due to static linkage which means the call to that function is getting set only once by the compiler which is in the base class.

Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without even knowing the kind of derived class object.

## __How does the compiler perform runtime resolution?__

The compiler maintains two things to serve this purpose:

__vtable:__ A table of function pointers, maintained per class.  
__vptr:__ A pointer to vtable, maintained per object instance.

![Alt text](../Images/Vtable.png "Vtable & vptr")

The compiler adds additional code at two places to maintain and use vptr.

1. Code in every constructor. This code sets the vptr of the object being created. This code sets vptr to point to the vtable of the class.

2. Code with polymorphic function call (obj->fun()). Wherever a polymorphic call is made, the compiler inserts code to first look for vptr using a base class pointer or reference. Once vptr is fetched, vtable of derived class can be accessed. Using vtable, the address of the derived class function can be accessed and called.

It is not necessary to use the keyword virtual in the derived class while declaring redefined versions of the virtual base class function.

Refer [Virtual Function Example.](../virtual_function_test_cases.cpp)

## __Static Functions:__

- static member function of a class cannot be virtual.
- Virtual functions are invoked when you have a pointer or reference to an instance of a class.
- Static functions aren’t tied to the instance of a class but they are tied to the class.
- C++ doesn’t have pointers-to-class, so there is no scenario in which you could invoke a static function virtually.
- static member function cannot be const and volatile.
