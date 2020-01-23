#include <iostream>
using namespace std; 

class bill
{
	int price; 
	int quantity; 
	int totalPrice; 
	
	public:
		void getData(); 
		void calculatePrice(); 
		void displayData(); 
}; 

void bill::calculatePrice()
{
	totalPrice = price * quantity; 
	cout << totalPrice<<endl; 
}

void bill::getData()
{
	cout << "Enter the quantity: "; 
	cin >> quantity; 
	cout << "Enter the price: "; 
	cin >> price; 
}

void bill::displayData()
{
	cout <<quantity; 
	cout <<"\t\t"; 
	cout <<price; 
	cout <<"\t\t"; 
	calculatePrice(); 
}

int main()
{
	bill item[10]; 
	int i; 
	
	for(i = 0; i < 3; i++)
	{
		cout << "\n\t\t**Enter details of item number "<<i+1<<"**\n"; 
		item[i].getData(); 
	}
	cout <<"\n"; 
	cout << "Quantity\tItem price\tTotal price\n"; 
	for(i = 0; i < 3; i++)
	{
		item[i].displayData(); 
	}
	
	return 0; 
}
