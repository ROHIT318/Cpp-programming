#include <iostream>

using namespace std; 

// At first defining a class for node
template <class T>
class dnode {
	public:
		T element; 
		dnode *next; 
		dnode *previous; 

		dnode(int e) {
			element = e; 
			next = NULL; 
			previous = NULL; 
		}
}; 

// For allowing us to travel the list bothside
template <class T>
class iterator {
	dnode<T> *actualNode; 
	public:
		iterator() {
			dnode<T> *node = NULL; 
			actualNode = node; 
		}
		~iterator() {
			if(actualNode == NULL) {
				actualNode = NULL; 
			}
		}

		dnode<T> *nextNode() {
			if(actualNode == NULL) {
				return NULL; 
			}
			actualNode = actualNode->next; 
			return actualNode; 
		}
		dnode<T> *previousNode() {
			if(actualNode == NULL) {
				return NULL; 
			}
			actualNode = actualNode->previous; 
			return actualNode; 
		}
}; 

template <class T>
class dlist {
	public: 
		dnode<T> *head; 
		dnode<T> *tail; 

		dlist() {
			head = new dnode<T>(); 
			tail = new dnode<T>(); 
		}
		~dlist() { 
			clear(); 
			delete head; 
			delete tail; 
		}
}

bool isempty() {
	return (head->next == NULL); 
}

void insertFirst(T &e) {
	if(isempty()) {
		dnode<T> *newNode = new dnode<T>(e); 
		head->next = newNode; 
		tail->previous = newNode; 
	}
	else {
		dnode<T> *actualFirst = head->next; 
		dnode<T> *newnode = new dnode<T>(e, actualFirst); 
		actualFirst->previous = newNode; 
		head->next = newNode; 
	}
}

void insertLast(T &e) {
	if(isempty()) {
		dnode<T> *newNode = new dnode<T>(e); 
		head->next = newNode; 
		tail->previous = newNode; 
	}
	else {
		dnode<T> *actualLast = tail->previous; 
		dnode<T> *newNode = new dnode<T>(e, NUll, actualLast); 
		actualLast->next = newNode; 
		tail->previous = newNode; 
	}
}

void insertBefore(dnode<T> *ref, T &e) {
	if(isempty()) {
		return false; 
	}
	dnode<T> *searchRef = head->next; 
	while( searchRef != NULL) {
		if(searchRef == ref) {
			break; 
		}
		searchRef = searchRef->next; 
	}
	if(searchRef == NULL) {
		return false; 
	}
	else {
		dnode<T> *beforeRef = searchRef->previous; 
		dnode<T> *newNode = new dnode<T>(e, searchRef, beforeRef); 
		if(beforeRef == NULL) {
			head->next = newNode; 
		}
		else {
			beforeRef->next = newNode; 
		}
		searchRef->previous = newNode; 
		return true; 
	}
}




int main() {



	return 0; 
}