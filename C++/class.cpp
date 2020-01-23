#include <iostream>

using namespace std; 

class lamborghini {
	private: 
		int topSpeed; 
		float accleration; 
		
	public:		
		void getInformation(int speed,float accl) {
			topSpeed = speed; 
			accleration = accl; 
		}
		
		void printInformation() {
			cout << "Top speed : "<<topSpeed<<endl; 
			cout << "Accleration : "<<accleration<<endl; 
			cout<<endl<<endl; 
		} 
		
		lamborghini() {
			cout << "Constructor created.\n";  
		}
}; 


int main() {
	lamborghini aventadore; 
	lamborghini murceileigo; 
	int speed; 
	float accleration; 
	
	cout << "Enter the top speed : "; 
	cin >> speed; 
	cout << "Enter accleration time : "; 
	cin >> accleration; 
	aventadore.getInformation(speed,accleration); 
	aventadore.printInformation(); 	
	
	cout << "Enter the top speed : "; 
	cin >> speed; 
	cout << "Enter accleration time : "; 
	cin >> accleration; 
	murceileigo.getInformation(speed,accleration); 
	murceileigo.printInformation(); 	
	
	
	return 0; 
}
