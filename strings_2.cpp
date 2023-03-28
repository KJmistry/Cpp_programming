// C++ Program to Demonstrate String Class
#include<iostream>
// for string class
#include<string>
using namespace std;

int main()
{
	char str[80] = "myFirstString"; 	// Size has to be predefined in character array
	string s("mySecondString"); 	        // Size not predefined in string
	
    // Printing character array and string
	cout << str << endl;
	cout << s << endl;

    /*---------------compare strings--------------*/

    string str_1("hello");
    string str_2("hello");
 
    // Comparing strings using compare()
    if (str_1.compare(str_2) == 0)
        cout << "Strings are equal";
    else
        cout << "Strings are unequal";

    string str_3("The Geeks for Geeks");


    /*-----------------find related----------------*/
 

    // find() returns position to first occurrence of substring "Geeks"
    cout << "First occurrence of \"Geeks\" starts from : ";
    cout << str_3.find("Geeks") << endl;
 
    // Prints position of first occurrence of any character of "reef" (Prints 2)
    cout << "First occurrence of character from \"reef\" is at : ";
    cout << str_3.find_first_of("reef") << endl;
 
    // Prints position of last occurrence of any character of "reef" (Prints 16)
    cout << "Last occurrence of character from \"reef\" is at : ";
    cout << str_3.find_last_of("reef") << endl;
 
    // rfind() returns position to last occurrence of substring "Geeks" Prints 14
    cout << "Last occurrence of \"Geeks\" starts from : ";
    cout << str_3.rfind("Geeks") << endl;
    

    /*--------------instrtion of string---------------*/
    
    
    string str_4("Geeksfor");
 
    // Printing the original string
    cout << str_4 << endl;
    // Inserting "Geeks" at 8th index position
    str_4.insert(8,"Geeks");    // Position must be within range 0 to strlen(string)
    // Printing the modified string Prints "GeeksforGeeks"
    cout << str_4 << endl;

    /*--------------clear string and check for empty--------------*/

    // Checking if string is empty
    (str_4.empty()==1) ? cout << "String is empty" << endl : cout << "String is not empty" << endl;
 
    
    return 0;
}
