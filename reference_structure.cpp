#include <iostream>
using namespace std;

struct Student {
    string name;
    string address;
    int rollNo;
};
/*  
    **If we remove & in below function, a new copy of the student object is created. 
    **We use const to avoid accidental updates in the function 
    **as the purpose of the function is to print s only.
*/
void print(const Student &s)
{
    cout << s.name << "  " << s.address << "  " << s.rollNo << '\n';
}
int main()
{
    Student s = {"Kshtij","Surat",36};
    Student& ref = s;
    print(ref);

    return 0;
}