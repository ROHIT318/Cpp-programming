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

int prec(char op) {
    if(op == '*' || op == '/') {
        return 2; 
    }
    else if(op == '+' || op == '-') {
        return 1; 
    }
    else if(op == '^') {
        return 3; 
    }
    else {
        return -1; 
    }
}

int isOperand (char ch) {
    if( (ch >= 'A' &&  ch <= 'Z') || (ch >= 'a' &&  ch <= 'z') )
        return 1;
    else
        return 0; 
}

void InfixToPostfix(string expression) {
    stack<char> finalExpr; 
    finalExpr.push('u'); 
    char ch, op; 

    for (int i = 0; i < expression.length(); i++) {
        op = expression[i]; 

		// If character is operand 
        if (isOperand(op) == 1) {
            cout << op; 
        }
        // If character is operator 
        else {
        	// If stack is empty 
            if (finalExpr.isempty() == 1) {
                finalExpr.push(op); 
            }
            else if (op == '(') {
                finalExpr.push('('); 
            }
            else if (op == ')') {
                while (ch != '(') {
                    ch = finalExpr.pop(); 
                    if (ch != '(') {
                        cout << ch; 
                    }
                }
            }
            else {
                char check = finalExpr.pop(); 
                while ( prec(check) >= prec(op) ) {
                    cout << check; 
                    check = finalExpr.pop(); 
                }
                finalExpr.push(check); 
                finalExpr.push(op); 
            }
        }
    }
    // Popping everything out 
    ch = finalExpr.pop(); 
    while(ch != 'u') {
    	if(ch != '(')
    		cout << ch; 
        ch = finalExpr.pop(); 
    }
}

int isOperand (string ch) {
    if( (ch >= "A" &&  ch <= "Z") || (ch >= "a" &&  ch <= "z") )
        return 1;
    else
        return 0; 
}

void PostfixToInfix(string expression) {
	stack<string> finalExpr; 
	string expr = ""; 
	
	for(int i = 0; i < expression.length(); i++) {
		string ch(1, expression[i]); 
		if(isOperand(ch) == 1) {
			finalExpr.push(ch); 
			// cout << ch; 
		}
		else {
			string first = finalExpr.pop(); 
			string second = finalExpr.pop(); 
			string final = "(" + second + expression[i] + first + ")"; 
			finalExpr.push(final); 
		}
	}
	expr = finalExpr.pop(); 
	cout << expr; 
}

int main() {
	string expr = /*"(a+b*c-d)/(e*f)"*/ "a+b*c-d"; 

	InfixToPostfix(expr); 
	
	cout << endl; 
    
    string Expr = "abc*+d+"; 
    
    PostfixToInfix(Expr); 

    return 0; 
}
