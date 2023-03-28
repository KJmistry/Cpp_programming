// Below is C++ program
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
// using namespace std::chrono;


int main()
{
    for (int i = 1; i <= 5; ++i)
    {
	    cout << i << " "<< flush;
	    cout << "\b\b"<< flush;
        // cout << "\b\b";
	    this_thread::sleep_for(std::chrono::seconds(1)); 
    }

// cout << "1 ";
// this_thread::sleep_for(chrono::seconds(1));
// cout << "1 ";
// this_thread::sleep_for(chrono::seconds(1));
// cout << "1 ";
// this_thread::sleep_for(chrono::seconds(1));
// cout << "1 ";
// this_thread::sleep_for(chrono::seconds(1));

cout << endl;
return 0;
}
