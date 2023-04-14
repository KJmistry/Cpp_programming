#include <iostream>
using namespace std;

int main()
{

/*----------------------defining and printing pair (Basic syntax)------------------------*/
    
    pair<int,int> p1 = {1,2};
    pair<char,string> p2 = {'c',"string"};

    cout << p1.first << endl;
    cout << p1.second << endl;

    cout << p2.first << endl;
    cout << p2.second << endl;

    cout << endl;


/*--------------------------------Example of nested pair---------------------------------*/

    pair<int, pair<int,int>> nested1 = {1, {2,3}};
    pair<string, pair<string,int>> nested2 = {"outer string", {"nested string",9}};

    cout << nested1.first << endl;
    cout << nested1.second.first << endl;
    cout << nested1.second.second << endl;    
    
    cout << nested2.first << endl;
    cout << nested2.second.first << endl;                               // accessing nested elements 
    cout << nested2.second.second << endl;

    cout << endl;

/*--------------------------------------Array of pair-------------------------------------*/

    pair<int,int> arr[] = {{1,1},{2,2},{3,3},{4,4}}; 

    cout << arr[0].first << endl;
    cout << arr[0].second << endl;

    cout << arr[1].first << endl;
    cout << arr[1].second << endl;

    cout << arr[2].first << endl;
    cout << arr[2].second << endl;

    cout << endl;

    return 0;
}