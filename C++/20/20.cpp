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
        void insert_head(int value); 
        void insert_last(int value); 
        void insert_position(int value, int position); 
        void delete_head(); 
        void delete_position(int position); 
        void delete_last(); 
        void reverse_list(); 
        void display_list(); 
}; 

void Llist::insert_head(int value) {
    node *temp; 
    if(head == NULL) {
        temp = new node(value); 
        head = temp; 
    }
    else {
        temp = new node(value); 
        temp->next = head; 
        head = temp; 
    }
}

void Llist::insert_last(int value) {
    node *temp = head, *ptr; 
    ptr = new node(value); 
    while(temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = ptr; 
}

void Llist::insert_position(int value, int position) {
    int counter = 1; 
    node *temp = head; 
    node *ptr = new node(value); 
    while(counter < position - 1) {
        temp = temp->next; 
        counter++; 
    }
    ptr->next = temp->next; 
    temp->next = ptr; 
}

void Llist::delete_head() {
    node *temp = head; 
    head = head->next; 
}

void Llist::delete_position(int position) {
	node *ptr; 
    int counter = 1; 
    node *temp = head; 
    
    while(counter < position-1) {
        temp = temp->next; 
        counter++; 
    }
    ptr = temp->next->next; 
    temp->next = ptr; 
}

void Llist::delete_last() {
    node *temp = head; 
    while(temp->next->next != NULL) {
        temp = temp->next; 
    }
    temp->next = NULL; 
}

void Llist::display_list() {
	node *temp = head; 
	
	cout << "\nList is: "; 
	while(temp != NULL) {
		cout << temp->data; 
		cout << "->"; 
		temp = temp->next; 
	}
	cout << "NULL"; 
	cout << endl << endl; 
}

void Llist::reverse_list() {
	node *temp = head->next, *ptr; 
	
	temp->next = NULL; 
	ptr = temp->next; 
	temp->next = head; 
	temp = temp->next; 
	while(temp != NULL) {
		ptr = temp->next; 
		temp = temp->next; 
		temp->next = ptr; 
	}
}

int main() {
    int input; 
    Llist list; 
    
    while(1) {
    	cout << "Press 1 for insertion.\n"; 
    	cout << "Press 2 for deletion.\n"; 
    	cout << "Press 3 for display.\n"; 
    	cout << "Press 4 for reversing the list.\n"; 
    	cout << "Press 5 for exit.\n"; 
    	cout << "Enter input: "; 
    	cin >> input; 
    	switch(input) {
    		case 1:
    			int element, insertion_input; 
    			cout << "\nEnter the element you want to insert: "; 
    			cin >> element; 
    			cout << "Press 1 for insertion at the beginning of list.\n"; 
    			cout << "Press 2 for insertion at the end.\n"; 
    			cout << "Press 3 to insert at the any position in the list.\n";  
    			cin >> insertion_input; 
    			switch(insertion_input) {
    				case 1:
    					list.insert_head(element); 
    					list.display_list(); 
    				break; 
    				case 2: 
    					list.insert_last(element); 
    					list.display_list(); 
    				break; 
    				case 3: 
    					int position; 
    					cout << "Enter the position you want to insert: "; 
    					cin >> position; 
    					list.insert_position(element, position); 
    					list.display_list(); 
    				break; 
    				default: 
    					cout << "Wrong input."; 
				}
    		break; 
    		case 2: 
    			int delete_position, delete_input;  
    			cout << "\nPress 1 for deletion at the beginning of list.\n"; 
    			cout << "Press 2 for deletion at the end.\n"; 
    			cout << "Press 3 to deletion at the any position in the list.\n"; 
    			cin >> delete_input; 
    			switch(delete_input) {
    				case 1: 
    					list.delete_head(); 
    					list.display_list(); 
    				break; 
    				case 2: 
    					list.delete_last(); 
    					list.display_list(); 
    				break; 
    				case 3: 
    					int position; 
    					cout << "\nEnter the position to delete: "; 
    					cin >> position; 
    					list.delete_position(position); 
    					list.display_list(); 
    				break; 
    				default: 
    					cout << "Wrong input"; 
				}
			break; 
			case 3: 
				cout << endl << endl; 
				cout << "List is "; 
				list.display_list(); 
			break; 
			case 4:
				cout << endl << endl; 
				cout << "After reversing the list: "; 
				list.reverse_list(); 
				list.display_list(); 
			break; 
			case 5:
				exit(1); 
			default: 
				cout << "\nWrong input\n"; 
		}
			
    }

    return 0; 
}
