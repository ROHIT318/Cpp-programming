#include <iostream>
#define size 10
int top = -1; 

using namespace std; 

template<class T> 
class stack {
    public: 
        int stack[size]; 

        void push(T element) {
            if(!isfull()) {
                top++; 
                stack[top] = element; 
            }
            else {
                cout << "\nStack overflow.\n"; 
            }
        }
        
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

        bool isempty() {
            if(top == 0) 
                return 1; 
            return 0; 
        }
        
        bool isfull() {
            if(top == size) 
                return 1; 
            return 0; 
        }
}; 

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
