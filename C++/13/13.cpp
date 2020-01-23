#include <iostream>

using namespace std;

template <class T>
class Vector {
    public:
        class node {
            public:
                T data;
                node *next;
                node(T value) {
                    data = value;
                    next = NULL;
                }
        };
        node *head = NULL;
        node *tail = NULL;
        Vector() {
            vect = NULL;
        }
        void push_back(T value) {
            cout << "1";
            node *ptr = new node(value);
            node *temp = head;
            cout << "2";
            if(head == NULL) {
                cout << "3";
                head = ptr;
            }
            else {
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = ptr;
            }
        }
        
        T pop_up() {
            node *temp = head, *ptr;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            ptr = temp->next;
            temp->next = NULL;
            return ptr->data;
        }

        int size() {    
            node *temp = this->head;
            int counter = 0;
            while(temp != NULL) {
                temp = temp->next;
                counter++;
            }
            return counter;
        }

        void display_vector() {
            node *ptr = this->head;
            for(node *ptr = this->head; ptr != NULL; ptr = ptr->next) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }


};


int main() {
    Vector<int> a;
    cout << "0";

    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    a.display_vector();



    getchar();
    return 0;
}