#include <iostream>

using namespace std; 

template <class T>
class dllist {
	class node {
		public:
			node *previous; 
			T data; 
			node *next; 
			node(T value) {
				data = value; 
				previous = NULL; 
				next = NULL; 
			}
	};
	node *head = NULL; 
	node *tail = NULL; 
	public:
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
				
				temp = head; 
				while(temp->next != NULL) {
					temp = temp->next; 
				}
				tail = temp; 
			}
		}
		
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
		
		void insertLast(T value) {
			node *temp; 
			node *ptr; 
			
			ptr = new node(value); 
			temp = head; 
			
			while(temp->next != NULL) {
				temp = temp->next; 
			}
			
			temp->next = ptr; 
			ptr->next = NULL; 
			ptr->previous = temp; 
			tail = ptr; 
		}

		void deleteHead() {
			node *temp; 
			temp = head; 

			temp = temp->next; 
			head = temp; 
			head->previous = NULL; 
		}

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

		void deleteLast() {
			node *temp; 
			temp = tail; 

			temp = temp->previous; 
			temp->next = NULL; 
			tail = temp; 
		}

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
		
		void displayList() {
			node *temp; 
			
			temp = head;
			while(temp != NULL) {
				cout << temp->data << " "; 
				temp = temp->next; 
			}
		}
};

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
