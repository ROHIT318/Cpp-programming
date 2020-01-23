#include <iostream>
#include <cmath>

using namespace std; 

class time {		
	public:
		int hh; 
		int mm; 
		int ss; 
		
		time()
		{	
			hh = 0; 
			mm = 0; 
			ss = 0; 
		}
		
		time(int hour, int minute, int second)
		{	
			hh = hour; 
			mm = minute; 
			ss = second; 
		}
		
		time operator+(time obj) {
			time t3; 
			t3.hh = 0; 
			t3.mm = 0; 
			t3.ss = 0; 
						
			t3.ss = ss + obj.ss; 
			while(t3.ss >= 60) {
				t3.mm = t3.mm + 1; 
				t3.ss = t3.ss - 60; 
			}  
			
			t3.mm = mm + obj.mm + t3.mm; 
			while(t3.mm > 60) {
				t3.hh = t3.hh + 1; 
				t3.mm = t3.mm - 60; 
			}  
			
			t3.hh = hh + obj.hh + t3.hh; 
			
			return t3; 
		}
		
		time operator-(time obj) {
			time t3; 
			t3.hh = (hh - obj.hh); 
			
			if(t3.hh < 0) {
				t3.mm = (60 - mm) + obj.mm; 
				t3.ss = (60 - ss) + obj.ss; 
				t3.hh = abs(t3.hh); 
				t3.mm--; 
				t3.hh--; 
				return t3; 
			}

			t3.mm = (mm - obj.mm); 
			if(t3.mm < 0) {
				t3.hh = t3.hh - 1; 
				t3.mm = abs(t3.mm); 
			}
			
			t3.ss = (ss - obj.ss); 
			if(t3.ss < 0) {
				t3.mm = t3.mm - 1; 
				t3.ss = abs(t3.ss); 
			}
			
			return t3; 
		}

		time operator++() {
			hh++; 
		}

		time operator--() {
			hh--; 
		}
		
		void printData() {
			cout << hh << ":" << mm << ":" << ss; 
		}
};


int main()
{
	time t1(2,26,45); 
	time t2(3,20,40); 
	
	time t3 = t1 + t2; 
	cout << "\n**Result after addition:**\n"; 
	t3.printData(); 	
	cout << "\n\n"; 
	
	t3 = t1 - t2; 
	cout << "\n**Result after subtraction:**\n"; 
	t3.printData(); 	

		
	return 0; 
}
