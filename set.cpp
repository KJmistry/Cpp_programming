#include <iostream>
#include <set>
using namespace std;

int main()
{   
    set<int> mySet;        
    
    mySet.insert(2);                    // myQueue = { 2, }
    mySet.insert(3);                    // myQueue = { 3, 2, }
    mySet.insert(5);                    // myQueue = { 5, 3, 2, }
    mySet.insert(5);                    // myQueue = { 5, 3, 2, }
    mySet.emplace(4);                   // myQueue = { 5, 4, 3, 2, }
    mySet.emplace(1);                   // myQueue = { 5, 4, 3, 2, 1, }
    mySet.emplace(1);                   // myQueue = { 5, 4, 3, 2, 1, }
    
    auto index1 = mySet.find(2);

    cout << *(index1) << endl;           // prints 2

    auto index2 = mySet.find(9);         // if element not present returns last index

    cout << *(index2) << endl;           // prints 5

    mySet.erase(2);                      // Erase element 2 from the set 

    /*
        index1 will still retain value 2 
        index2 will decrement its pointer value by one address hence it will now points to value 4 
    */    

    cout << *(index1) << endl;           // still prints 2
    cout << *(index2) << endl;           // prints 4

    cout << mySet.count(1) << endl;      // will always return value 1 OR 0 (since it stores unique values only)   

    // For deleting multiple element

    auto iterator1 = mySet.find(1);
    auto iterator2 = mySet.find(3);

    mySet.erase(iterator1,iterator2);    // erase(starting index, ending index)

    // erases from (starting index) to (endindex - 1)

    // other functions like : lower_bound & upper_bound not included in this code !

    return 0;               
}
