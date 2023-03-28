#include <iostream>
#include <string>
#include<fstream>
// using namespace std;
int main()
{   
    int k;
    char name[100];

    /*-------------------------  use of cout / cin  -------------------------*/
    std::cout << "hello\n";       // pushing "hello" to console (cout << ), endl -> pushing to next line.
    std::cin >> k;
    std::cin >> name;
    std::cout << "value entered " << k << " unit\n";

    std::cout << "Name entered " << name << "\n";
    /*-------------------------- use of getline() -------------------------------*/
    std::string str;
    std::cin.ignore();                      // to resolve the problem occured due to presence of new line character 
    getline(std::cin, str);                 // read string streams till it encounters a newline (accepts spaces)
    std::cout << str << std::endl;
    str += "gh";
    // str.erase(1,2);
    // std::cout << str << std::endl;
    str.replace(2,5,"aaa");
    std::cout << str << std::endl;
    

    return 0;
}
