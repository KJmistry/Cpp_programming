/***********************************************NOTE****************************************************/
/*
    @ DO ADD BREAK POINTS AT EACH STATEMENTS AFTER REMOVING/DELETING-ELEMENT TOPIC 
    @ BECAUSE NO FURTHER PRINT STATEMENTS ARE ADDED FOR RESULT VALIDATION
    @ KEEP ON ANALYSING VARIABLE WINDOW WHILE SINGLE STEPPING TO VALIDATE MODIFIED VECTOR
*/
/*******************************************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

int main()
{   

/*--------------------------creating and accessing element of simple vector-----------------------------*/


    vector<int> v;                      // similar to dynamic array (creats empty container) 

    v.push_back(10);                    // to add(append) value to the vector 
    v.emplace_back(20);                 // functions like push_back only, but it is faster than push_back

    cout << v[0] << " ";                // accessing vector element
    cout << v[1] << " ";

    cout << endl;

/*-------------------------------------creating vector of pair-------------------------------------------*/

    vector<pair<int,int>> pairVector = {{1,1}};

    pairVector.push_back({2,2});        
    pairVector.emplace_back(3,3);       // no need to add {} while using emplace_back, it will autometically consider it as a pair

    for(int i = 0; i < 3 ; i++)
    {
        cout << pairVector[i].first << ", ";
        cout << pairVector[i].second << endl;
    }

/*--------------------------------------pre-defining size of vector-------------------------------------------*/

    vector<int> v1(5,1);                // v1 = {1, 1, 1, 1, 1,}
    vector<int> v2(5);                  // v1 = {garbage value/0 compiler dependent}

    // even after pre-defining the size of vector it can be further expanded if needed !
    
    vector<int> v3(v1);                 // copying v1 in v3 [v3 = v1]

    cout << v1[0] << endl; 
    cout << v2[0] << endl;

/*--------------------------------------removing/deleting element from vector-------------------------------------------*/

    v1 = {1, 2, 3, 4, 5,};              // v1 = {1, 2, 3, 4, 5,}
    v1.erase(v1.begin()+1);             // v1 = {1, 3, 4, 5,}

    cout << v1[1] << endl;              // prints 3 

    // to delete multiple elements (range of element) : vector_name.erase(start_point, end_point)

    v1 = {1, 2, 3, 4, 5,};              // v1 = {1, 2, 3, 4, 5,}
    v1.erase(v1.begin(),v1.end()-1);    // v1 = { 5 }   [deletes elements from start point to the element before the end point]
    
    // v1.begin = 0th index & v1.end = index next after the last element 

    cout << v1[0] << endl;              // prints 5

/*--------------------------------------inserting element in a vector-------------------------------------------*/

    v1 = {1, 2, 3, 4, 5,};              // v1 = {1, 2, 3, 4, 5,}
    cout << "size of v1 before inseting : "<< v1.size() << endl;

    v1.insert(v1.begin(),0);            // inserts 0 at begining v1 = {0, 1, 2, 3, 4, 5,}
    cout << v1[0] << endl;              // prints 0

    cout << "size of v1 after inseting : "<< v1.size() << endl;

    // for inserting multiple element : vector.insert(start_point, number of element, value of the element)

    v1 = {1, 2, 3, 4, 5,};              // v1 = {1, 2, 3, 4, 5,}
    v1.insert(v1.begin() + 1, 3, 0);    // inserts 3 zeros at index 1 [ v1 = { 1, 0, 0, 0, 2, 3, 4, 5,} ]

    // inserting vector inside the vector : vector.insert(start_point, start point of vector to be inserted, end point of vector to be inserted )

    v1 = {1, 2, 3, 4, 5,};              // v1 = {1, 2, 3, 4, 5,}
    v2 = {9, 9};

    v1.insert(v1.begin(),v2.begin(),v2.end());  
                                        // v1 after insteting v2 at begining : {9, 9, 1, 2, 3, 4, 5}

/*--------------------------------------popping the element from the vector-------------------------------------------*/

    v1.pop_back();                      // v1 after popping : {9, 9, 1, 2, 3, 4,}
    v1.pop_back();                      // v1 after popping : {9, 9, 1, 2, 3,}

/*-----------------------------------------------swapping two vectors-------------------------------------------------*/

    v1 = {1, 1, 1};                        
    v2 = {9, 9};

    v1.swap(v2);                        // After swapping : v1 = {9, 9}  &  v2 = {1, 1, 1}

/*-----------------------------------------------erasing entire vector-------------------------------------------------*/
    v1.clear();

    return 0;    
}