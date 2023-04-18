#include <iostream>
#include <set>
using namespace std;

int main()
{   
    multiset<int> mySet;       
    
    mySet.insert(2);                    // myQueue = { 2, }
    mySet.insert(3);                    // myQueue = { 3, 2, }
    mySet.insert(5);                    // myQueue = { 5, 3, 2, }
    mySet.insert(5);                    // myQueue = { 5, 5, 3, 2, }
    mySet.emplace(4);                   // myQueue = { 5, 5, 4, 3, 2, }
    mySet.emplace(1);                   // myQueue = { 5, 5, 4, 3, 2, 1, }
    mySet.emplace(1);                   // myQueue = { 5, 5, 4, 3, 2, 1, 1, }
    
    mySet.erase(1);                     // erases all ones present in container

    mySet.erase(mySet.find(5));         // find and remove only first entry

    return 0;               
}
