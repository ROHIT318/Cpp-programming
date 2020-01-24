/*  Write a program to evaluate a posix expression. The posix expression is to be passed as the input to the
	constructor of a class.
*/
#include <iostream>
using namespace std; 
/* stack creation starts from here */
// increase the size as per expression length
#define size 10
int top = -1; 

template<class T> 
class stack {
    public: 
        T stack[size]; 
        int flag = 0; 

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
            if(top == -1) 
                return 1; 
            return 0; 
        }
        
        bool isfull() {
            if(top == size) 
                return 1; 
            return 0; 
        }
}; 
/* stack creation ends here */
// function for evaluation postfix expression
void postfixEvaluation(string expression) {
	stack<int> finalResult; 
	int first, second, result; 
	int ch; 
	
	for(int i = 0; i < expression.length(); i++) {
		ch = expression[i]; 
		if(ch > 47) {
			ch -= 48; 
			finalResult.push(ch); 
		}
		else {
			// converting from string to integer type
			second = finalResult.pop(); 
			first = finalResult.pop(); 
			// working with ASCII code
			if(ch == 43) {
				result = first + second; 
			}
			else if(ch == 45) {
				result = first - second; 
			}
			else if(ch == 47) {
				result = first / second; 
			}
			else{
				result = first * second; 
			}
			finalResult.push(result);  
		}
	}
	result = finalResult.pop(); 
	cout << result; 
}
// main function needs modification hs to add infinite while and switch cases
int main() {
	string expr = "45*98-*"; 
	postfixEvaluation(expr); 
	
	return 0; 
}
