#include <iostream>
#include <math.h>

using namespace std; 

class integer {
	private:
		int a; 
		
	public:
		/*integer(int b):a(b) { 
		}*/
		
		void store(int b) {
			a = b; 
		}
		
		void printInteger() {
			// cout << a <<endl; 
			// cout << this->a <<endl; 
			cout << (*this).a << endl; 
		}
};

class function {
	public: 
		int number1;
		int number2;
		int sum(int a, int b);
		int multiply(int a, int b);
		void division(int a, int b);
};

int function::sum(int a, int b) {
	sum = a + b;
	return sum;
}

int fuction::multiply(int a, int b) {
	int multiply = a * b;
	return multiply;
}

float function::division(int a, int b) {
	float result = a / b;
	return result;
}



int main() {
	integer c; 
	
	c.store(69); 
	 
	c.printInteger(); 
	
	return 0; 
}
