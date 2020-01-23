#include <iostream>

using namespace std; 

class Sequence {
    public:
    	class node {
			public: 
				string data; 
        		node *next; 
        		node(string value) {
        		    data = value; 
        		    next = NULL; 
        		}
        }; 
    	node *head = NULL; 
    	Sequence() {
		}
    	void Insert(string str); 
    	void Delete(); 
    	void Find(); 
    	void Print(); 
}; 

void Sequence::Insert(string str) {
	node *ptr, *temp, *pptr; 
	
	ptr = head; 
	temp = new node(str); 
	cout << "ONE";
	
	if(ptr == NULL) {
		head = temp; 
	}
	else {
		cout << "TWO";
		pptr = ptr; 
		while(ptr != NULL) {
			cout << "THREE TWICE";
			if(ptr->data > temp->data) {
				cout << "FOUR";
				if(pptr == ptr) {
					temp->next = head; 
					head = temp; 
				}
				else {
					cout << temp->data; 
					pptr->next = temp; 
					temp->next = ptr; 
				}
				return; 
			}
			pptr = ptr;
			ptr = ptr->next; 
		}
	}
}

/*void Sequence::Delete(string str) {
	
}

void Sequence::Find(string str) {
	
}*/

void Sequence::Print() {
	node *temp = head; 
	while(temp != NULL) {
		cout << temp->data; 
		if(temp->next != NULL) {
			cout << " "; 
		}
		temp = temp->next; 
	}
}

int main() {
	Sequence list; 
	string str1 = "Rohit"; 
	string str2 = "Ahemdabad", str3 = "cat"; 
	
	list.Insert(str1); 
	list.Insert(str2); 
	cout << endl;
	list.Insert(str3);
	// list.Print(); 
	
	return 0; 
}
