/*	Write an Object Oriented Program using C++ to create polynomial type Objects. These Polynomial type
	Objects are created using Singly Link List type Objects, which are again created using Node type multi-field
	objects. Every object may take different type of numeric data values (Use Template). Each object is created
	with their related operations. In additions do the followings for the polynomial type objects:
	a. Addion of two polynomials – using function and operator overloading
	b. Subtraction of two polynomials - using function and operator overloading
	c. Mulplictiaon of two polynomials - using function and operator overloading
	d. Evaluation of a polynomial – using Horner’s rule
	e. Creation of polynomial using input redirection operation (>>)
	f. Printing the polynomial using output redirection operation (<<)
	All kind of exception must be properly handled by the applicaon system.
*/
#include <iostream>
#include <math.h>
using namespace std;
// function to create polynomial equation type objects
class polynomial {
    public:
		// declaration of local class
        class node {
        public:
    	    int coeff;
    	    int pow;
    	    node* next;
			// constructor
            node(int value, int power) {
                coeff = value;
                pow = power;
                next = NULL;
            }
	    };
        node *poly;
		// constructor
        polynomial() {
            poly = NULL;
        }
		// overloading ">>" operator
        friend istream&operator>>(istream &input, polynomial &obj) {
        	node *ptr, *temp, *head;
	    	int power, flag = 0;
	    	int coeff;
	
    		cout << "Enter the highest power of equation: ";
    		input >> power;
	
    		while (power != -1) {
				// if head is NULL
    		    if(flag == 0) {
    		        cout << "Enter the co-efficient of power " << power << ": ";
    		        input >> coeff;
    		        temp = new node(coeff, power);
    		        head = temp;
   			        ptr = temp;
        		    flag = 1;
        		}
        		else {
        		    cout << "Enter the co-efficient of power " << power << ": ";
        		    input >> coeff;
        	    	temp = new node(coeff, power);
        		    ptr->next = temp;
        		    ptr = temp;
        		}
        		power--;
    		}
    		obj.poly = head; 
    		return input; 
		}
		// overloading "<<" operator
		friend ostream&operator<<(ostream &output, polynomial &obj) {
    		node *temp = obj.poly; 
    		int power = temp->pow; 
			if(temp->coeff >= 0) {
    			output << temp->coeff << "X^" << temp->pow;
			}
			else {
				output << " - ";
				output << abs(temp->coeff) << "X^" << temp->pow;
			}
			temp = temp->next;

    		while(temp != NULL) {
    			if(temp->coeff >= 0) {
    				output << " + ";
    				output << temp->coeff << "X^" << temp->pow;
				}
				else {
					output << " - ";
					output << abs(temp->coeff) << "X^" << temp->pow;
				}
        		temp = temp->next;
        		power--;
    		}
    		return output; 
    	}		

		polynomial operator+(polynomial &obj); 
        polynomial operator-(polynomial &obj); 
        polynomial operator*(polynomial &obj); 
        friend int horner(polynomial &obj, int x);
};
//function to find horner rule result of polynomial equation
int horner(polynomial &obj, int x) {
	int sum = 0; 
	for(node *temp = obj.poly; temp != NULL; temp = temp->next) {
		sum += temp->coeff * pow(x, temp->pow); 
	}
	return sum; 
}
// function to overload "+" operator
polynomial polynomial::operator+(polynomial &obj) {
    polynomial var;
    node *temp1, *temp2, *temp3 = NULL, *r_temp, *p_temp;
    temp1 = this->poly;
    temp2 = obj.poly;

    while(temp1 != NULL || temp2 != NULL) {
        r_temp = new node(temp1->coeff + temp2->coeff, temp1->pow);
        if(temp3 == NULL) {
            temp3 = r_temp;
            p_temp = temp3;
        }
        else {
            p_temp->next = r_temp;
            p_temp = p_temp->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    var.poly = temp3;
    return var;
}
// function to overload "-" operator
polynomial polynomial::operator-(polynomial &obj) {
    polynomial var;
    node *temp1, *temp2, *temp3 = NULL, *r_temp, *p_temp;
    temp1 = this->poly;
    temp2 = obj.poly;

    while(temp1 != NULL || temp2 != NULL) {
        r_temp = new node(temp1->coeff - temp2->coeff, temp1->pow);
        if(temp3 == NULL) {
            temp3 = r_temp;
            p_temp = temp3;
        }
        else {
            p_temp->next = r_temp;
            p_temp = p_temp->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    var.poly = temp3;
    return var;
}
// function to overload "*" operator
polynomial polynomial::operator*(polynomial &obj) {
	int mul, power; 
	node *temp1 = this->poly; 
	node *temp2 = obj.poly; 
	node *temp3 = NULL, *r_temp, *check, *head = NULL; 
	polynomial var; 
	
	for(temp1 = this->poly; temp1 != NULL; temp1 = temp1->next) {
		for(temp2 = obj.poly; temp2 != NULL; temp2 = temp2->next) {
			mul = temp1->coeff * temp2->coeff; 
			power = temp1->pow + temp2->pow; 
			check = head; 
			while(check != NULL && check->pow > power) {
				check = check->next; 
			}
			if(check != NULL && check->pow == power) {
				check->coeff += mul; 
			}
			else {
				r_temp = new node(mul, power); 
				if(temp3 == NULL) {
					temp3 = r_temp; 
					head = temp3; 
				}
				else {
					temp3->next = r_temp; 
					temp3 = temp3->next; 
				}
			}
		}
	}
	var.poly = head; 
	return var; 
}
// main function
int main() {
    polynomial a, b, c; 
    int result, x; 

	cin >> a; 
	cin >> b; 
	cout << endl; 
	cout << endl; 
	cout << a; 
	cout << b;     
    while(1) {
		cout << "For addition press 1.\n";     		
    	cout << "For subtraction press 2.\n"; 
    	cout << "For multiplication press 3.\n"; 
    	cout << "For evaluating equation Hornet's rule press 4.\n"; 
    	cout << "Enter input: "; 
    	int input; 
		cin >> input; 
    	switch(input) {
    		case 1: 
    			c = a + b; 
    			cout << c; 
    		break; 
    		case 2: 
    			c = a - b; 
    			cout << c; 
    		break; 
    		case 3: 
    			c = a * b; 
    			cout << c; 
    		break; 
    		case 4: 
    			cout << "Enter the value of x: "; 
    			cin >> x; 
    			result = horner(a, x); 
    			cout << "The result is " << x; 
    		break; 
    		case 5:
    			exit(0); 
    		break; 
    		default: 
    			cout << "Wrong input"; 
    		break; 
		}
	}
    
    return 0;
}
