#include <iostream>
#include <algorithm>
using namespace std;

bool compare_pair( pair<int,int> &pair1, pair<int,int> &pair2)
{
    if(pair1.second < pair2.second) return true;
    if(pair1.second > pair2.second) return false;

    // if same 

    if(pair1.first > pair2.first) return true;
    else return false;
}

int main()
{   
    pair <int,int> arr[] = {{1,2},{2,5},{1,3},{2,2}};
    unsigned long int size = (sizeof(arr)/sizeof(arr[0]));

    sort(arr,arr+size);                 // default sort 

    for(long unsigned int index = 0; index < size; index++)
    {
        cout << arr[index].first << " , " << arr[index].second << endl;
    }

    cout << "------------------------------" << endl; 

    sort(arr,arr+size,compare_pair);    // custom sort, method defined inside function compare_pair

    for(long unsigned int index = 0; index < size; index++)
    {
        cout << arr[index].first << " , " << arr[index].second << endl;
    }

    return 0;
}