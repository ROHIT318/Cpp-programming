#include <iostream>

using namespace std; 

class DLlist {
	public:
		int data; 
		DLlist *previous; 
		DLlist *next; 
		
		DLlist() {
			data = NULL; 
			previous = NULL; 
			next = NULL;  
		}
		
		DLlist(int value) {
			data = value; 
			previous = NULL; 
			next = NULL; 
		}
};

DLlist head, tail; 

void insertNode() {
	DLlist temp; 
	int value; 
	
	cout << "Enter the value to insert: "; 
	cin >> value; 
	
	DLlist ptr(value); 
	
	if(head.data == tail.data) {
		head = ptr; 
	}
	else {
		temp = head; 
		while(temp.next != tail) {
			temp = *(temp.next); 
		}
		temp.next = ptr; 
		ptr.previous = temp; 
		ptr.next = head; 
		head.previous = temp; 
	}
}

void displayList() {
	temp = head; 
	
	while(temp.next != head) {
		cout << temp.data >> "->" ; 
	}
	cout >> "head"; 
}

int main() {
	int check = 1; 
	
	while(check) {
		insertNode(); 
		cout << "\n\n";  
		cin >> check; 
	}
	
	displayList(); 
	
	return 0; 
}
