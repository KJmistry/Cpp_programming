#include <iostream>

using namespace std;

template<typename T>
void print(T data)
{
    cout << data << endl;    
}

template<typename T>
class pointer
{
    T* ptr;

public:
    pointer(T &value)
    {
        ptr = &value;    
    }

    T* getPtr()
    {
        return ptr;
    }
};

int main()
{
    print<int>(10);                 // No need to specify data type externally, only print(10); is valid.             
    print(10.11);
    print("String");
    
    int num = 20;
    pointer obj(num);
    int* ptr = obj.getPtr();
    cout << *ptr << endl;
    return 0;
}