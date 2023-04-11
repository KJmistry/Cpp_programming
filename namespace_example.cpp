#include <iostream>

using namespace std;

namespace kshitij
{   
    int a = 10;
    void func()
    {
        cout << "KSHITIJ" << endl;
    }
    namespace nest
    {
        void func()
        {
            cout << "Inside nest" << endl;
        }
    }
}

namespace kshitij                           // allowed !
{

}
void func()
{
    cout << "Outside kshitij namespace" << endl;
}

int main()
{   
    // using namespace kshitij::nest;
    // using namespace kshitij;

    int a = 10;
    func();
    kshitij::func();
    kshitij::nest::func();

    return 0;
}