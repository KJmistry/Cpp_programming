#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2 ,3 ,4 ,5};
    vector<int>::iterator index = v1.begin();

    cout << v1.back() << endl;                      // printing last element
    // auto i = v1.end();                           // using auto to avoid writing vector iterator syntax every time 
    // cout << *(--i) << endl;

    cout << *(index) << endl;
    cout << v1[0] << " " << v1.at(0) << endl;
    
    index++;

    cout << *(index) << endl;

    cout << "--------printing using for loop---------" << endl;

    for(vector<int>::iterator index = v1.begin(); index != v1.end();index++)
    {
        cout << *(index) << endl;
    }

    //-------------using auto keyword--------------
    
    for(auto index = v1.begin(); index != v1.end();index++)
    {
        cout << *(index) << endl;
    }

    //----------------short syntax-------------------
    for(auto index : v1)
    {
        cout << index << endl;
    }


    return 0;
}