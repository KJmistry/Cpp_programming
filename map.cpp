#include <iostream>
#include <map>

using namespace std;

int main()
{   
    map <int, string> data;             // map <key, value>  (stores unique keys only and in sorted order)
    data[0] = "Kshitij";
    data.insert({2,"twistern"});
    data.emplace(1,"dep");
    data.emplace(5,"dep");

    /*
        after executing above 3 instruction, the map generated is:
        data:
            [0] : Kshitij
            [1] : dep
            [2] : twistern
    */


    // cout << "---" <<data.size() << endl; 

    map <pair<int,int>,int> myData;

    myData[{1,1}] = 10;
    myData[{2,1}] = 30;
    myData[{1,2}] = 20;

    // printing map

    for(auto it_data : data)
    {
        cout << it_data.first << " : " << it_data.second << endl;
    }
    
    for(auto it_myData : myData)
    {
        cout << "{ " << it_myData.first.first << " , "<< it_myData.first.second << " }" <<  " : " << it_myData.second << endl;
    }

    // accessing individual element

    cout << data[1] << endl;        // prints "dep"
    cout << data[4] << endl;        // prints NULL since 4 key doesn't exist

    cout << myData[{1,1}] << endl;  // prints 10

    // access using iterator 

    auto it_1 = data.find(2);
    cout << it_1->first << " : " << it_1->second << endl;

    // auto it_2 = data.find(10);
    // cout << it_2->first << " : " << it_2->second << endl;    
    /*
        Above code results into segmentation fault, since 10 key is not present
        also iterators in map are not dereferencable, hence can not be validated
    */   

    return 0;
}