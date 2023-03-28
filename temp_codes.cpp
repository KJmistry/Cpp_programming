#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str("Geek");
 
    // Printing the original string
    cout << str << endl;
 
    // Inserting "Geeks" at 8th index position
    str.insert(2,"Geeks");
 
    // Printing the modified string
    // Prints "GeeksforGeeks"
    cout << str << endl;
 
    return 0;
}