#include <iostream>
#include <queue>
using namespace std;

int main()
{   
    priority_queue<int> myQueue;        // known as MAX HEAP

    /*--OPERATIONS POSSIBLE ON PRIORITY QUEUE--*/
    
    myQueue.push(2);                    // myQueue = { 2, }
    myQueue.push(3);                    // myQueue = { 3, 2, }
    myQueue.push(5);                    // myQueue = { 5, 3, 2, }
    myQueue.emplace(4);                 // myQueue = { 5, 4, 3, 2, }
    myQueue.emplace(1);                 // myQueue = { 5, 4, 3, 2, 1, }

    cout << myQueue.top() << endl;      // prints 5

    myQueue.pop();                      // myQueue = { 4, 3, 2, 1 }

    cout << myQueue.top() << endl;      // prints 4

    priority_queue<int, vector<int>, greater<int>> Queue;           // giving priority to minimun number, known as MIN HEAP 

    Queue.push(2);                      // Queue = { 2, }
    Queue.push(3);                      // Queue = { 2, 3, }
    Queue.push(5);                      // Queue = { 2, 3, 5, }
    Queue.emplace(4);                   // Queue = { 2, 3, 4, 5, }
    Queue.emplace(1);                   // Queue = { 1, 2, 3, 4, 5, }

    cout << Queue.top() << endl;        // prints 1

    Queue.pop();                        // myQueue = { 2, 3, 4, 5, }

    cout << Queue.top() << endl;        // prints 2
    return 0;
}
