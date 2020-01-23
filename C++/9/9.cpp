#include <iostream>
#define size 10
int top = -1; 

using namespace std; 

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
			second = finalResult.pop(); 
			first = finalResult.pop(); 
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

int main() {
	string expr = "45*98-*"; 
	postfixEvaluation(expr); 
	
	return 0; 
}
