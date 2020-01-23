#include <iostream>

using namespace std; 

class birthday {
	private:
		int date;
		int month;
		int year;

	public:
		birthday(int d,int m,int y):month(m),date(d),year(y) {
		}
		void printDate() {
			cout << "Birth date is "<<date<<"/"<<month<<"/"<<year<<endl; 
		}
}; 

class person {
	private:
		string name; 
		birthday bd; 
		
	public:
		person(string nm,birthday b):name(nm),bd(b) {
		}
		void printInfo() {
			cout << name <<endl; 
			bd.printDate(); 
		}
};

int main() {
	birthday bd(05,04,1999); 
	person p("ROHIT SHARMA",bd); 
	
	p.printInfo(); 
	
	return 0; 
}
