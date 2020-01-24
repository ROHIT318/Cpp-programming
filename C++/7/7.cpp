/* Design a class Stack using template class. Write proper functions for performing PUSH, POP operaons on
    generic data types.
*/

#include <iostream>
// size of the stack increase the value for storing more values
#define size 10
int top = -1; 

using namespace std; 

// declaring class stack of generic data type
template<class T> 
class stack {
    public:
        // declaration of data member
        int stack[size]; 

        // function to push element in stack
        void push(T element) {
            if(!isfull()) {
                top++; 
                stack[top] = element; 
            }
            else {
                cout << "\nStack overflow.\n"; 
            }
        }
        
        // function to pop element in stack
        T pop() {
            if(isempty()) {
                cout << "\nStack underflow.\n"; 
            }
            else {
                T element = stack[top]; 
                top--; 
                return element; 
            }
        }

        // function to check if stack is empty
        bool isempty() {
            if(top == 0) 
                return 1; 
            return 0; 
        }
        
        // function to check if stack is full
        bool isfull() {
            if(top == size) 
                return 1; 
            return 0; 
        }
}; 

// need to modify main function using infinite while and switch cases
int main() {
    stack<int> a; 

    a.push(9); 
    a.push(8); 
    int number = a.pop(); 
    cout << number <<endl; 
    number = a.pop(); 
    cout << number <<endl; 


    return 0; 
}
