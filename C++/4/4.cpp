#include <iostream>

using namespace std; 

template <class T>
void bubbleSort(T a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j])
                swap(a, i, j); 
        }
    }
}

template <class T>
void swap(T a, int position1, int position2) {
    T temp = a[position1]; 
    a[position1] = a[position2]; 
    a[position2] = temp; 
}

int main() {
    int a[20], noElements; 

    cout << "Enter the number of elements in array: "; 
    cin >> noElements; 
    for(int i = 0; i < noElements; i++) {
        cout << "Enter the element number " << i+1 <<": "; 
        cin >> a[i]; 
    }
    bubbleSort(a, noElements); 

    for(int i = 0; i < noElements; i++) {
        cout << a[i] << " "; 
    }

    return 0; 
}
