/* 	Write a program to create a class DLList to implement doubly linked list of template type. The program
	should have support for ordered inseron and deleon of a node. Provide a method revlist() that will contain
	the nodes of the doubly linked list but in reverse order.
*/
#include <iostream>
using namespace std; 
// class for creating doubly link list type objects
template <class T>
class dllist {
	// class for creating nodes
	class node {
		public:
			node *previous; 
			T data; 
			node *next; 
			// constructor
			node(T value) {
				data = value; 
				previous = NULL; 
				next = NULL; 
			}
	};
	// decalaration of head and tail of the list
	node *head = NULL; 
	node *tail = NULL; 
	public:
		// function to insert node at head position
		void insertFirst(T value) {
			node *temp, *ptr; 
			
			temp = new node(value); 
			if(head == NULL) {
				head = temp; 
				tail = head; 
			}
			else {
				head->previous = temp;
				temp->next = head; 
				temp->previous = NULL; 
				head = temp; 
				// maybe not needed
				temp = head; 
				while(temp->next != NULL) {
					temp = temp->next; 
				}
				tail = temp; 
			}
		}
		// function to insert node at a particular position.
		void insertPosition(T value, int position) {
			node *temp = head; 
			node *ptr = new node(value); 
			int counter = 1; 
			
			while(counter < position) {
				temp = temp->next; 
				counter++; 
			}
			ptr->previous = temp->previous; 
			temp->previous->next = ptr; 
			ptr->next = temp; 
			temp->previous = ptr; 
		}
		// function to insert node at tail position
		void insertLast(T value) {
			node *temp; 
			node *ptr; 
					
			ptr = new node(value); 
			temp = head; 
			/* short method:
			tail->next = ptr;
			ptr->next = NULL;
			tail = ptr;
			*/
			// OR you can follow this long method:
			while(temp->next != NULL) {
				temp = temp->next; 
			}
			
			temp->next = ptr; 
			ptr->next = NULL; 
			ptr->previous = temp; 
			tail = ptr; 
		}
		// function to delete node at head position
		void deleteHead() {
			node *temp; 
			temp = head; 

			temp = temp->next; 
			head = temp; 
			head->previous = NULL; 
		}
		// function to delete a node from a particular position
		void deletePosition(int position) {
			int counter = 1; 
			node *temp, *ptr, *nptr; 
			temp = head; 

			while(counter < position) {
				temp = temp->next; 
				counter++; 
			} 
			ptr = temp->previous; 
			nptr = temp->next; 
			ptr->next = nptr; 
			nptr->previous = ptr; 
		}
		// function to delete the tail node
		void deleteLast() {
			node *temp; 
			temp = tail; 

			temp = temp->previous; 
			temp->next = NULL; 
			tail = temp; 
		}
		// function to reverse list
		void revList() {
			node *temp = head;  
    		node *ptr = NULL; 
			node *nptr = NULL;  
      
    		while(temp != NULL) {
    			nptr = temp->next; 
    			ptr = temp->previous; 
    			temp->previous = temp->next; 
    			temp->next = ptr; 
    			temp = nptr; 
			}
			temp = head; 
			head = tail; 
			tail = temp; 
		}
		// function to display the list
		void displayList() {
			node *temp; 
			
			temp = head;
			while(temp != NULL) {
				cout << temp->data << " "; 
				temp = temp->next; 
			}
		}
};
// main function
int main() {
	dllist<int> a; 
	
	while(1) {
		cout << "\n\nFor insertion press 1.\n"; 
		cout << "For deletion press 2.\n"; 
		cout << "For reversing the list press 3.\n"; 
		cout << "For exit press 4.\n"; 
		
		int input; 
		cout << "Enter input: "; 
		cin >> input; 
		switch(input) {
			case 1: 
				cout << "For inserting at the beginning of list press 1.\n"; 
				cout << "For inserting at the end of list press 2.\n"; 
				cout << "For inserting at a given position press 3.\n"; 
				int insert_input, element; 
				cout << endl; 
				cout << "Enter input: "; 
				cin >> insert_input; 
				cout << endl; 
				switch(insert_input) {
					case 1: 
						cout << "\n\nEnter the element to insert: "; 
						cin >> element; 
						a.insertFirst(element);
						cout << endl; 
						a.displayList(); 
						cout << endl;  
						break; 
					case 2: 
						cout << "Enter the element to insert: "; 
						cin >> element; 
						a.insertLast(element);
						cout << endl; 
						a.displayList(); 
						break; 
					case 3: 
						int insert_position; 
						cout << "Enter the element to insert: "; 
						cin >> element; 
						cout << "Enter the position to insert: "; 
						cin >> insert_position; 
						a.insertPosition(element, insert_position);
						cout << endl; 
						a.displayList(); 
						break; 
					default: 
						cout << "Wrong input. "; 
						cout << endl; 
						break; 
				}
				break; 
			case 2:
				cout << "\n\nFor deleting at the beginning of list press 1.\n"; 
				cout << "For deleting at the end of list press 2.\n"; 
				cout << "For deleting at a given position press 3.\n"; 
				int delete_input; 
				cout << "Enter input:"; 
				cin >> delete_input; 
				
				switch(delete_input) {
					case 1:
						a.deleteHead(); 
						cout << endl; 
						a.displayList(); 
						cout << endl; 
						break; 
					case 2: 
						a.deleteLast(); 
						cout << endl; 
						a.displayList(); 
						cout << endl; 
						break;  
					case 3: 
						int position; 
						cout << "Enter the position to delete: "; 
						cin >> position; 
						a.deletePosition(position); 
						cout << endl; 
						a.displayList(); 
						cout << endl; 
						break; 
				}
				break; 
			case 3: 
				cout << endl; 
				a.revList(); 
				cout << endl; 
				a.displayList(); 
				break; 
			case 4: 
				exit(1); 
			default: 
				cout << "Wrong choice.\n"; 
				break; 
		}
	}

	return 0; 
}
