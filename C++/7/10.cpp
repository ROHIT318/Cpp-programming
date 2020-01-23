#include <iostream>
using namespace std; 

template <class U>
class Rupee; 

template <class T>
class Dollar {
    T dollarPrice; 
    T marketValue; 

    public: 
        Dollar() {
            marketValue = 69;  
        }

        Dollar operator=(Rupee &obj) {
            dollarPrice = obj.rupeePrice * marketValue; 
        }

        void getData(); 
        void showData(); 
}; 

template <class U>
class Rupee {
    U rupeePrice; 
    U marketValue; 

    public: 
        Dollar() {
            marketValue = 1 / 69;  
        }

        Dollar operator=(Dollar &obj) {
            rupeePrice = obj.dollarPrice * marketValue; 
        }

        void getData(); 
        void showData(); 
}; 

void Rupee :: getData() {
    cout << "Enter the amount in Rs: "; 
    cin >> rupeePrice; 
}

void Rupee :: showData() {
    cout << rupeePrice; 
}

void Dollar :: getData() {
    cout << "Enter the amount in $: "; 
    cin >> dollarPrice; 
}

void Dollar::showData() {
    cout << dollarPrice; 
}


int main() {
    Dollar<float>d1, d2; 
    Rupee<float>r1, r2; 

    r1.getData(); 
    d1 = r1; 
    d1.showData(); 

    d2.getData(); 
    r2 = d2; 
    d2.showData(); 

    return 0; 
}