#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l(5,1);                       // l = { 1, 1, 1, 1, 1 }
    
    l.push_back(9);
    l.emplace_back(9);
    
    /* l = { 1, 1, 1, 1, 1, 9, 9, } */
    
    l.push_front(9);                        // Not possible in vectors
    l.emplace_front(9);

    /* l = { 9, 9, 1, 1, 1, 1, 1, 9, 9, } */

    /* All other functions are similar to vectors, explained in vector.cpp program */

    l.remove_if([](int it) { return it != 1; });

    /* l = { 1, 1, 1, 1, 1, } */
    
    for(auto it : l)
        cout << it;
    
    cout << endl;
    return 0;
}