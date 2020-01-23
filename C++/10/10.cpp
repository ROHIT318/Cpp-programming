#include <iostream>

using namespace std;

class Rupees;

class Dollar {
	public:
		float dollarValue; 
		Dollar operator=(Rupees &r);
		void inputDollar(float value);
		void displayDollar();
};

class Rupees {
	public:
		float rupeesValue; 
		Rupees operator=(Dollar &d);
		void inputRupees(float value);
		void displayRupees();
};

void Dollar::inputDollar(float value) {
	dollarValue = value;
}

void Rupees::inputRupees(float value) {
	rupeesValue = value;
}

Rupees Rupees::operator=(Dollar &d) {
	Rupees r;
	float var = d.dollarValue; 
	r.rupeesValue = var * 70.65;
	cout << r.rupeesValue;
	return r;
}

Dollar Dollar::operator=(Rupees &r) {
	Dollar d;
	float var = r.rupeesValue;
	d.dollarValue = var / 70.65;
	return d;
}

void Rupees::displayRupees() {
	cout << rupeesValue;
}

void Dollar::displayDollar() {
	cout << dollarValue;
}

int main() {
	Dollar d1, d2;
	Rupees r1, r2;
	int input;
	float currency;

	while(1) {
		cout << "\nFor Converting dollar to rupees press 1.";
		cout << "\nFor converting rupees to dollar press 2.";
		cout << "\nPress 3 for exit";
		cout << "\nEnter input: ";
		cin >> input; 
		switch(input) {
			case 1:
				cout << "Enter the value of dollar to be converted: ";
				cin >> currency;
				d1.inputDollar(currency);
				r1 = d1;
				cout << "\nRupees = ";
				r1.displayRupees();
			break;
			case 2:
				cout << "Enter the value of rupees to be converted: ";
				cin >> currency;
				r1.inputRupees(currency);
				d2 = r2;
				cout << "\nDollar = ";
				d2.displayDollar();
			break;
			case 3:
				exit(0);
			break;
			default:
				cout << "Wrong input";
			break;
		}
	}
	
	return 0;
}
