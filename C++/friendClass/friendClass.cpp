#include <iostream>

using namespace std; 

class integer {
	private:
		int a; 
		friend void printName(); 
		
	public:
		void store(int b) {
			a = b; 
		}
		printInteger() {
			cout << a <<endl; 
		}
};

int main() {
	integer c; 
	
	c.store(4); 
	c.printInteger(); 
	
	return 0; 
}
