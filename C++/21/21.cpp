#include <iostream>

using namespace std; 

class Llist {
    public:
    	class node {
			public: 
				int data; 
        		node *next; 
        		node(int value) {
        		    data = value; 
        		    next = NULL; 
        		}
        }; 
    	node *head = NULL; 
		void insert_in_queue(int value); 
		void delete_in_queue(); 
		void display_queue(); 
		int length_of_queue(); 
}; 

void Llist::insert_in_queue(int value) {
	node *temp = this->head, *ptr; 
	
	if(temp == NULL) {
		head = new node(value); 
	}
	else {
		while(temp->next != NULL) {
			temp = temp->next; 
		}
		ptr = new node(value); 
		temp->next = ptr; 
	}
}

void Llist::delete_in_queue() {
	node *temp; 
	temp = head->next; 
	free(head); 
	head = temp; 
}

void Llist::display_queue() {
	node *temp = this->head; 
	
	cout << "Queue: "; 
	while(temp != NULL) {
		cout << temp->data << " "; 
		temp = temp->next; 
	}
}

int Llist::length_of_queue() {
	int counter = 1; 
	node *temp = this->head; 
	
	while(temp->next != NULL) {
		temp = temp->next; 
		counter++; 
	}
	return counter; 
}

int main() {
	Llist queue; 
	int input; 
	
	while(1) {
		cout << "\n\nPress 1 for insertion in queue.\n"; 
		cout << "Press 2 for deletion in queue.\n"; 
		cout << "Press 3 for length of queue.\n"; 
		cout << "Press 4 for exit.\n"; 
		cout << "Enter input: "; 
		cin >> input; 
		switch(input) {
			case 1: 
				int element; 
				cout << "Enter the element you want to insert: "; 
				cin >> element; 
				queue.insert_in_queue(element); 
				queue.display_queue(); 
			break; 
			case 2: 
				queue.delete_in_queue(); 
				queue.display_queue(); 
			break; 
			case 3: 
				int queue_length; 
				queue_length = queue.length_of_queue();  
				cout << "Length of queue is " << queue_length; 
			break; 
			case 4: 
				exit(1); 
			break; 
			default: 
				cout << "Wrong input"; 
		}
	}
	
	return 0; 
}
