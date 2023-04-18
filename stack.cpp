#include <iostream>
#include <stack>
using namespace std;

int main()
{   
    stack<int> myStack;

    /*--OPERATIONS POSSIBLE ON STACK--*/
    
    myStack.push(1);                    // myStack = { 1, }
    myStack.push(2);                    // myStack = { 1, 2, }
    myStack.push(3);                    // myStack = { 1, 2, 3, }
    myStack.emplace(4);                 // myStack = { 1, 2, 3, 4, }
    myStack.emplace(5);                 // myStack = { 1, 2, 3, 4, 5, }

    cout << myStack.top() << endl;      // prints 5

    myStack.pop();                      // myStack = { 1, 2, 3, 4, }                               
    myStack.pop();                      // myStack = { 1, 2, 3, }  

    cout << myStack.top() << endl;      // prints 3

    cout << myStack.empty() << endl;    // prints 0 [False : Stack is not empty]

    stack<int> temp;
    myStack.swap(temp);                 // swapping stack
    return 0;
}
