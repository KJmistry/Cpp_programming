# Pairs

For storing two items in a single variable of any datatype.

Syntax:

    pair< data_type1 ,data_type2 > var_name = { value1 , value2 }
    Ex: pair<int,int> p = {1,2}

Different pair operations [sample program](../pairs.cpp)

# Vectors

vector is a type of container and is dynamic in nature.(can be expanded at run time dynamically)

Syntax:

    vector <data_type> variable_name; // will create an empty container
    Ex: vector<int> intVec;

Different vector operations [sample program](../vectors.cpp)

# Iterator

Usefull for accessing members of vectors.

syntax:

    vector<data_type>::iterator iterator_name = vector_name.reference // reference = .begin, .end, .rend, .rbegin

Different iteraror operations [sample program](../iterator.cpp)

# List

It is similar as vector, the difference is list also provides front operations like adding element at the front of the list. (since doubly linkd list is maintained in list)  
In vectors the fornt is also possible using insert but insert is comparatively costly. (since singly linkd list is maintained in vectors)  

Different vector operations [sample program](../list.cpp)

## __dque is also similar to list and vectors__

# Stack 

It is also the container that follows LIFO. There is no mechanism like index.

Different stack operations [sample program](../stack.cpp)

# Queue

Similar as stack but follows FIFO.

Different queue operations [sample program](../queue.cpp)

# Priority Queue

Different priority-queue operations [sample program](../priority_queue.cpp)

# set

Stores unique things and in sorted order.

Different set operations [sample program](../set.cpp)

# Multi set

Similar to set (stores in sorted order) but it allows multiple entries of same element.

Different multiset operations [sample program](../multiset.cpp)

# Unordered set

Similar to set, stores unique entries but not in sorted order.

# Map

Store data with indexing mechinism which is known as key to the perticular value. stores unique keys only and in sorted order.

Different map operations [sample program](../map.cpp)

# Multi map

Similar to map, the only difference that it allwos same key multiple time and in sorted order. (same as set and multiset)

# Unordered map

Similar to map, the only difference that it does not store values in sorted form but stores unique keys.
