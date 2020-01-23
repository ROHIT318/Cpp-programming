#include <iostream>

using namespace std; 

template <class T>
class polynomial {
	class node {
		public:
			T coeff; 
			int pow; 
			node *next; 
			
			node(T value, int power) {
				coeff = value; 
				pow = power; 
				next = NULL; 
			}
	}; 
	node *head; 
	public: 
		void takeInput(); 
		void displayPolynomial(); 
		
		polynomial operator+(polynomial &obj) {
			node *temp1 = this->head, *temp2 = obj.head; 
			node *headTemp; 
			node *temp3, *ntemp; 
			int coeff, power; 
	
			while(temp1->pow >= 0 || temp2->pow >= 0) {
				if(temp1->pow == temp2->pow) {
					coeff = temp1->coeff + temp2->coeff; 
					power = temp1->pow; 
					ntemp = new node(coeff, power); 
					if(temp3 == NULL) {
						headTemp = ntemp; 
						temp3 = headTemp; 
					}
					else {
						temp3->next = ntemp; 
						temp3 = ntemp; 
					}
					temp1 = temp1->next; 
					temp2 = temp2->next; 
				}
				else if(temp1->pow > temp2->pow) {
					coeff = temp1->coeff; 
					power = temp1->pow; 
					ntemp = new node(coeff, power); 
					if(temp3 == NULL) {
						headTemp = ntemp; 
						temp3 = headTemp; 
					}
					else {
						temp3->next = ntemp; 
						temp3 = ntemp; 
					}
					temp1 = temp1->next; 
				}
				else if(temp1->pow < temp2->pow) {
					coeff = temp2->coeff; 
					power = temp2->pow; 
					ntemp = new node(coeff, power); 
					if(temp3 == NULL) {
						headTemp = ntemp; 
						temp3 = headTemp; 
					}
					else {
						temp3->next = ntemp; 
						temp3 = ntemp; 
					}
					temp2 = temp2->next; 
				}
				power--; 
			}
		} 
}; 

template <class T>
void polynomial<T>::takeInput() {
	int power, coeff, flag = 0; 
	node *ntemp; 
	
	cout << "Enter the highest power: "; 
	cin >> power; 
	
	while(power != -1) {		
		cout << "Enter the co-effecient of power " << power << ": "; 
		cin >> coeff; 
		
		node *temp = new node(coeff, power); 
		if(flag == 0) {
			head = temp; 
			ntemp = temp; 
			flag = 1; 
		}
		ntemp->next = temp; 
		ntemp = temp; 
		
		power--; 
	}
}

template <class T>
void polynomial<T>::displayPolynomial() {
	node *temp = head; 
	int power; 
	
	while(temp != NULL) {
		cout << temp->coeff << "X^" << temp->pow << " + "; 
		temp = temp->next; 
	}
	cout << endl; 
}


int main() {
	polynomial<int> a; 
	polynomial<int> b; 
	
	a.takeInput(); 
	b.takeInput(); 
	
	a.displayPolynomial(); 
	b.displayPolynomial(); 
	
	return 0; 
}
