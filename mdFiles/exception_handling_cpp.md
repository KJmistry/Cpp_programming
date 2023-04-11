# Exception Handling in C++

One of the advantages of C++ over C is Exception Handling.C++ provides the following specialized keywords,

__try:__ Represents a block of code that can throw an exception.  
__throw:__ Used to throw an exception. Also used to list the exceptions that a function throws but doesn’t handle itself.  
__catch:__ Represents a block of code that is executed when a particular exception is thrown.  

main advantages of exception handling over traditional error handling:

- Separation of Error Handling code from Normal Code.
- Functions/Methods can handle only the exceptions they choose.
- Grouping of Error Types.

Refer [Sample Code](../exception_handling.cpp)

Basic rules:

- There can be multiple catch blocks based on exception type.
- Implicit type conversion doesn’t happen for primitive types.(Throwing char won't get implicitly converted to int if, int type catch block is present)
- If an exception is thrown and not caught anywhere, the program terminates abnormally.
- A derived class exception should be caught before a base class exception.
- In C++, all exceptions are unchecked,(compiler doesn’t check whether an exception is caught or not)
- Dynamic Exception Specification. Refer [Example.](../exception_dynamic_specification.cpp)
- Try/catch blocks can be nested. Also, an exception can be re-thrown using "throw;"
- When an exception is thrown, all objects created inside the enclosing try block are destroyed before the control is transferred to the catch block.

## Stack Unwinding

Stack Unwinding is the process of removing function entries from function call stack at run time. The local objects are destroyed in reverse order in which they were constructed.It is generally related to Exception Handling.

when an exception occurs, the function call stack is linearly searched for the exception handler, and all the entries before the function with exception handler are removed from the function call stack.

Stack unwinding is a process of calling the destructors (whenever an exception is thrown) for all the automatic objects constructed at run time.

Refer [Example.](../stack_unwinding.cpp)

## Catching Base and Derived Classes as Exceptions

Refer Example [Stack Unwinding(../base_derived_class_exception.cpp)

In C++ both base and derived classes can be caught as exceptions using the catch block. while catching a base class, it will also catch any derived classes of that base class.

Refer [Example.](../catching_derived_class_exception.cpp)

- When an exception is thrown, destructors of the objects (whose scope ends with the try block) are automatically called before the catch block gets executed.
- Destructors are only called for the completely constructed objects. When the constructor of an object throws an exception, the destructor for that object is not called.
