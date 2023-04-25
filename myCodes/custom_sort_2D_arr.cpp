#include <iostream>
#include <algorithm>
using namespace std;

bool custom(const int* arr1,const int* arr2)
{

    if(arr1[0] > arr2[0])
        return true;
    if(arr1[1] > arr2[1])
        return true;
    if(arr1[2] > arr2[2])
        return true;
    return false;
}
int main()
{   
    int arr [3][3] = {{2,1,2},{2,1,4},{1,3,5}};
    int n = sizeof(arr) / sizeof(arr[0]);
   // sort(begin(arr),end(arr),custom);
    sort(arr, arr + 3, custom);
    // bool i = custom(arr[0],arr[2]);
    //sort( &arr[0][0] , &arr[2][0] ,custom);
    // sort(&arr[0],&arr[2],custom);

    for(int i = 0; i<3 ; i++)
    {
        for(int j = 0; j<3 ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // int row = 3,col = 3;
    // int** arr = new int*[row];

    // for(int i = 0; i < row ; i++)
    // {
    //     *(arr+i) = new int[col];
    //     for(int j = 0;j < col;j++)
    //     {
    //         cin >> *(*(arr+i)+j);
    //     }
    // }

    // cout << "before" << arr[1][0] << endl;
    // sort(*arr,*arr+row,custom);
    // cout << "after" << arr[1][0] << endl;
    return 0;
}
