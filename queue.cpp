#include <iostream>
#include <queue>
using namespace std;

int main()
{   
    queue<int> myQueue;

    /*--OPERATIONS POSSIBLE ON QUEUE--*/
    
    myQueue.push(1);                    // myQueue = { 1, }
    myQueue.push(2);                    // myQueue = { 1, 2, }
    myQueue.push(3);                    // myQueue = { 1, 2, 3, }
    myQueue.emplace(4);                 // myQueue = { 1, 2, 3, 4, }
    myQueue.emplace(5);                 // myQueue = { 1, 2, 3, 4, 5, }

    cout << myQueue.back() << endl;     // prints 5
    cout << myQueue.front() << endl;    // prints 1

    myQueue.back() += 5;                // myQueue = { 1, 2, 3, 4, 10, }

    myQueue.pop();                      // myStack = { 2, 3, 4, 10}

    cout << myQueue.back() << endl;     // prints 10
    cout << myQueue.front() << endl;    // prints 2

    myQueue.pop();                      // myStack = { 3, 4, 10}  
    cout << myQueue.front() << endl;    // prints 3

    return 0;
}
