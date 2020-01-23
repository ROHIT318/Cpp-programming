#include <iostream>

using namespace std; 

class variable {
	public:
		// member variable
		int integer; 
		
		// constructor
		variable() {
		}
		
		// Another constructor
		variable(int a):integer(a) {
		}
		
		// overloading operator function
		variable operator+(variable &obj) {
			variable res; 
			res.integer = this->integer * obj.integer;  
			return res; 
		}
		
		void printInteger() {
			cout << this->integer; 
		}
};

int main() {
	variable firstInteger(5),secondInteger(5); 
	
	cout <<"Integers are : "; 
	firstInteger.printInteger(); 
	cout << " and "; 
	secondInteger.printInteger(); 
	
		
	// Doing multiplication instead of addition
	variable sum = firstInteger + secondInteger; 
	
	cout <<"\nSum is "<<sum.integer; 
	
	return 0; 
}



/*if(temp1->pow == temp2->pow) {
		temp3 = new(struct node); 
		temp3->pow = temp1->pow; 
		temp3->coeff = temp1->coeff + temp2->coeff; 
		temp1 = temp1->next; 
		temp2 = temp2->next; 
		ntemp = temp3; 
	}
	else if(temp1->pow > temp2->pow) {
		temp3 = new(struct node); 
		temp3->coeff = temp1->coeff; 
		temp1 = temp1->next; 
	}
	else if(temp1->pow < temp2->pow) {
		temp3 = new(struct node); 
		temp3->coeff = temp2->coeff; 
		temp2 = temp2->next; 
	    }
	    else if(temp1 == NULL){
		        while(temp2 != NULL) {
		        	temp3 = new(struct node); 
		        	temp3->coeff = temp2->coeff; 
		        }
	        }
        } */




















