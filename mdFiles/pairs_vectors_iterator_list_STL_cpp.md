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

