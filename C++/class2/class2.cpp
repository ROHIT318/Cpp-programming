#include <iostream>
#include "myClass.h"

using namespace std; 

int main() {
	myClass obj; 
	myClass *objptr = &obj; 
	int number2; 
	
	objptr = &obj; 
	
	cout << "Enter the number:"; 
	cin >> number2; 
	
	obj.getNumber(number2); 
	obj.printNumber(objptr); 
	
	return 0; 
}
