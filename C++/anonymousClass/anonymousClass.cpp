#include <iostream>

using namespace std; 

typedef class {
    int a; 

    public:
        void getData() {
            cout << "Enter a: "; 
            cin >> a; 
        }
        void showData() {
            cout << "Value of a is " << a; 
        }
}obj; 

int main() {
    obj obj1; 

    obj1.getData(); 
    obj1.showData(); 

    obj obj2; 

    obj2.getData(); 
    obj2.showData(); 

    return 0; 
}