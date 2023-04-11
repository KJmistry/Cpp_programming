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

## Virtual Destructor

A is the parent of B and B is the parent of C (A->B->C). creating object of C using dymamic memmory allocation. While deleting the object, only the destructor of super parent will get executed. (Ideally destructor of all class should get called).

Making base class destructor virtual guarantees that the object of derived class is destructed properly.

## Virtual Constructor

C++ being a statically typed language, it is meaningless to the C++ compiler to create an object polymorphically.

What type of object to be created is a compile-time decision from the C++ compiler perspective. If we make a constructor virtual, the compiler flags an error. In fact, except inline, no other keyword is allowed in the declaration of the constructor.

## Run-Time Type Information (RTTI)

Mechanism that exposes information about an object’s data type at runtime and is available only for the classes which have at least one virtual function.

__Runtime Casts:__  
Checks that the cast is valid.__Beneficial when we need to cast a pointer from a base class to a derived type__  

Two types of casting:  

__Upcasting:__ When a pointer or a reference of a derived class object is treated as a base class pointer.  
__Downcasting:__ When a base class pointer or reference is converted to a derived class pointer.

Using __dynamic_cast__: In an inheritance hierarchy, it is used for downcasting a base class pointer to a child class. On successful casting, it returns a pointer of the converted type and, however, it fails if we try to cast an invalid type such as an object pointer that is not of the type of the desired subclass. Dynamic_cast uses RTTI.  

- Useful to perform safe casting by taking care of corresponding class type of which object actually is.(Since it returns null if object pointer is of different type)
- Validation of object class type is done using RTTI(add overhead, one can disable RTTI if not required).
- If compiling after disabling RTTI results into an undefined behaviour if using dynamic cast.

Refer [RTTI Example.](../RunTimeTypeInfo_RTTI.cpp)

## Creating private virtual function

Refer [Private Virtual function Example.](../private_virtual_function.cpp)

## Inline Virtual Functions

Virtual functions can be overridden by the derived class. They are used to achieve Runtime polymorphism or say late binding or dynamic binding.  
Inline functions are used to replace the function calling location with the definition of the inline function at compile time. They are used for efficiency.  

- By default, all the functions defined inside the class are implicitly or automatically considered as inline except virtual functions.
- Inline is a request to the compiler and its compilers choice to do inlining or not.
- Virtual function called using a base class reference or pointer, cannot be inlined because the call is resolved at runtime.
- Virtual function called using the object of that class, can be inlined because the compiler knows the exact class of the object at compile time.

Refer [Inline Virtual function Example.](../inline_virtual_function.cpp)

## Pure Virtual Functions

Implementation of all function cannot be provided in a base class.such class is called abstract class.

A pure virtual function (or abstract function) in C++ is a virtual function for which we can have implementation, But we must override that function in the derived class, otherwise the derived class will also become abstract class.

Syntax:

```
    virtual ret_type fun_name() = 0;
```

- A class is abstract if it has at least one pure virtual function.
- We can have pointers and references of abstract class type.
- If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.
- An abstract class can have constructors.
- An abstract class in C++ can also be defined using struct keyword.

Refer [Pure Virtual function Example.](../pure_virtual_function.cpp)

## Pure Virtual Destructor

It is possible to have a pure virtual destructor.If a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor.

The reason why body is required: destructors (unlike other functions) are not actually ‘overridden’, rather they are always called in the reverse order of the class derivation. This means that a derived class destructor will be invoked first, then the base class destructor will be called. If the definition of the pure virtual destructor is not provided, then what function body will be called during object destruction. Therefore the compiler and linker enforce the existence of a function body for pure virtual destructors.

- Class becomes an abstract class when it contains a pure virtual destructor.

Refer [Pure Virtual Destructor Example.](../pure_virtual_destructor.cpp)
