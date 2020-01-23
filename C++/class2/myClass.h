#ifndef MYCLASS_H
#define MYCLASS_H

using namespace std; 

class myClass
{
	private: 
		int number; 
		friend void printNumber(myClass &object); 
		
	public: 
		void getNumber(int number1) {
			number = number1; 
		}  
		void printNumber(myClass &object) {
			cout << "Number is "<<object->number; 
		}
		
	protected: 
		
};

#endif
