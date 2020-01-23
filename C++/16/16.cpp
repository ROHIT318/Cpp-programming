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
        Llist operator+(int value); 
        Llist operator+(int value); 
        void insert_position(int value, int position); 
        void delete_head(); 
        void delete_position(int position); 
        void delete_last(); 
        void reverse_list(); 
        void display_list(); 
}; 

Llist Llist::operator+(int value) {
	node *temp = head, *ptr; 
    ptr = new node(value); 
    while(temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = ptr; 
}

Llist Llist::operator-(int value) {
	node *temp = head, *ptr; 
    
    while(temp->data != value && temp != NULL) {
    	ptr = temp; 
        temp = temp->next; 
    	
    }
    if(temp->next != NULL) {
    	ptr->next = temp->next; 
	}
}


int main() {
	
	
	
	return 0; 
}
