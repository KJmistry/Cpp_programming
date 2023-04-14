# Standard Template Library

The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators.

Working knowledge of [__template classes__](./Templates_cpp.md) is a prerequisite for working with STL.

The STL provides a range of containers, such as vectors, lists, and maps, as well as algorithms for searching, sorting and manipulating data. Provides a way to write generic, reusable code that can be applied to different data types.

## Key components of the STL

__Containers:__ The STL provides a range of containers, such as vector, list, map, set, and stack, which can be used to store and manipulate data.  
__Algorithms:__ The STL provides a range of algorithms, such as sort, find, and binary_search, which can be used to manipulate data stored in containers.  
__Iterators:__ Iterators are objects that provide a way to traverse the elements of a container. The STL provides a range of iterators, such as forward_iterator, bidirectional_iterator, and random_access_iterator, that can be used with different types of containers.  
__Function Objects:__ Function objects, also known as functors, are objects that can be used as function arguments to algorithms. They provide a way to pass a function to an algorithm, allowing you to customize its behavior.  
__Adapters:__ Adapters are components that modify the behavior of other components in the STL. For example, the reverse_iterator adapter can be used to reverse the order of elements in a container.  

## 4 component of STL

- Algorithms
- Containers
- Functors
- Iterators

### __1.Algorithm__

Designed to be used on a range of elements. They act on containers and provide means for various operations for the contents of the containers.(sorting,searching,array algorithm,partition etc.)  
[sort example.](../sort_algorithm_STL.cpp)  
[search example.](../search_algorithm_STL.cpp)

### __2.Containers__

Containers or container classes store objects and data.

- Total seven standards “first-class” container classes.
- Three container adaptor classes.
- Only seven header files that provide access to these containers or container adaptors.
