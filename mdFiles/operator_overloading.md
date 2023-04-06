# Operator Overloading

Operator overloading is a compile-time polymorphism. It is an idea of giving special meaning to an existing operator in C++ without changing its original meaning.

- Redefining the meaning of operators really does not change their original meaning, instead, they have been given additional meaning along with their existing ones.
- Name of an operator function is always the operator keyword followed by the symbol of the operator, and operator functions are called when the corresponding operator is used.

Refer Cpp Code for [Operator overloading.](../operator_overloading.cpp)

__Almost all operators can be overloaded except a few. Following is the list of operators that cannot be overloaded:__

```
sizeof
typeid
Scope resolution (::)
Class member access operators (.(dot), .* (pointer to member operator))
Ternary or conditional (?:)
```

- For operator overloading to work, at least one of the operands must be a user-defined class object.
- Assignment Operator: Compiler automatically creates a default assignment operator with every class. The default assignment operator does assign all members of the right side to the left side and works fine in most cases (this behavior is the same as the copy constructor).
- Conversion Operator: We can also write conversion operators that can be used to convert one type to another type. Refer Cpp Code for [Conversion Operator.](../conversion_operator.cpp)
- Overloaded conversion operators must be a member method. Other operators can either be the member method or the global method.
- Any constructor that can be called with a single argument works as a conversion constructor, which means it can also be used for implicit conversion to the class being constructed. Refer cpp [Example.](../implicit_conversion.cpp)

## Copyconstructor Vs assignment operator

Copy constructor and Assignment operator are similar as they are both used to initialize one object using another object, but they are different.

__Copy constructor:__ called when a new object is created from an existing object. It creates a separate memory block for the new object. It is an overloaded constructor. C++ compiler implicitly provides a copy constructor, if no copy constructor is defined in the class. [className(const className &obj)]

__Assignment Operator:__ called when an already initialized object is assigned a new value from another existing object. It does not create a separate memory block. It is a bitwise operator. A bitwise copy gets created, if the Assignment operator is not overloaded. [obj2 = obj1;]

__If a class doesn’t contain pointers, then there is no need to write assignment operator and copy constructor.__

## Default Assignment Operator and References

__The compiler doesn’t create default assignment operator in the following cases:__

1. Class has a non-static data member of a const type or a reference type.
2. Class has a non-static data member of a type that has an inaccessible copy assignment operator.
3. Class is derived from a base class with an inaccessible copy assignment operator.

Refer [Example.](../overloading_assignment_operator.cpp)(overloading assignment operator)  
Refer [Example.](../overloading_cout.cpp)(overloading cout operator)
Refer [Example.](../overloading_cout.cpp)(overloading array index operator)
