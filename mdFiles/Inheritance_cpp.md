# Inheritance

All the public and protected data members and member functions of the base class. Private members are not inherited.

## __Properties which a derived class doesn’t inherit from its parent class:__

__Constructors and destructor:__ The constructors and destructor of a base class are not inherited by a derived class. However, the constructor of the base class can be invoked explicitly from the derived class constructor using the initialization list.

__Friend functions:__ The friend functions of a base class are not inherited by a derived class. Friend functions are those functions that have access to the private and protected members of a class.

__Overloaded operators:__ The overloaded operators of a base class are not inherited by a derived class. Overloaded operators are those operators that are redefined to perform specific operations on the objects of a class. However, a derived class can overload the operators that are inherited from its parent class.

While having different parameterized constructors in Base and Derived classa, and creating object of derived class. [(Example)](../inheritance_characteristics.cpp)

## when more restrictive access is given to a derived class method

Refer [Example.](../more_restrictive_derived_class.cpp)

## Object slicing

When a derived class object is assigned to a base class object in C++, the derived class object’s extra attributes are sliced off (not considered) to generate the base class object; and this whole process is termed object slicing. A derived class object can be assigned to a base class object, but the other way is not possible.

Refer Example [Object Slicing.](../more_restrictive_derived_class.cpp)

- Object slicing doesn’t occur when pointers or references to objects are passed as function arguments since a pointer or reference of any type takes the same amount of memory.
- Object slicing can be prevented by making the base class function pure virtual thereby disallowing object creation. It is not possible to create the object of a class that contains a pure virtual method.

## Hiding of all Overloaded Methods with Same Name in Base Class

If a derived class redefines the base class member method then all the base class methods with the same name become hidden in the derived class.

Refer [Example.](../hiding_overloaded_methods.cpp)

__Difference between Inheritance and Friendship in C++:__ In C++, friendship is not inherited. If a base class has a friend function, then the function doesn’t become a friend of the derived class(es).

Go through Inheritance topic covered in [OOP Basics](./oop_cpp.md)
