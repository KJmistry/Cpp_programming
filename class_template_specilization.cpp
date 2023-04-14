#include <iostream>
using namespace std;

template <typename T>
class Test
{
public:
    T variable;
    Test(T var) : variable(var)
    {
        cout << "General template object \n";
    }
};

template <>
class Test <int>
{
public:
    int variable;
    Test(int var) : variable(var)
    {
        cout << "Specialized template object\n";
    }
};

int main()
{
	Test<int> a(10);
	Test<char> b('K');
	Test<float> c(10.0);
	return 0;
}
