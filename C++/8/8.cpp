/*  Write a program in C++ to generate postfix expression from the infix form and vice-versa. The infix expression
	and the postfix expression in respective cases are to be passed as the input to the constructor of a class.
*/
#include <iostream>
using namespace std;
/* creating stack for conversion operations */
// increase the size as per expression size
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
/* creation of stack done */

// function to compare the precedence of two mathematical symbols
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

// function to check if the symbol is an operand or not (parameter is character type)
int isOperand (char ch) {
    if( (ch >= 'A' &&  ch <= 'Z') || (ch >= 'a' &&  ch <= 'z') )
        return 1;
    else
        return 0; 
}

// function to convert Infix expression to postfix
void InfixToPostfix(string expression) {
    stack<char> finalExpr; 
	// pushing "u" into stack for identifying the last element
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
                    if (ch != '(')
                        cout << ch; 
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

// function to check if the character is an operand (parameter is string type)
int isOperand (string ch) {
    if( (ch >= "A" &&  ch <= "Z") || (ch >= "a" &&  ch <= "z") )
        return 1;
    else
        return 0; 
}
// function for converting postfix expression to infix expression
void PostfixToInfix(string expression) {
	stack<string> finalExpr; 
	string expr = ""; 
	
	for(int i = 0; i < expression.length(); i++) {
		string ch(1, expression[i]); 
		if(isOperand(ch) == 1) {
			finalExpr.push(ch);
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
// in main function needs to add infinite while and switch cases
int main() {
	string expr = /*"(a+b*c-d)/(e*f)"*/ "a+b*c-d"; 

	InfixToPostfix(expr); 
	
	cout << endl; 
    
    string Expr = "abc*+d+"; 
    
    PostfixToInfix(Expr); 

    return 0; 
}
