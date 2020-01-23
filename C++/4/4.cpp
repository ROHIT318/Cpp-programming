/*  Write a program implementing Bubble sort on a set of data using function template. Write another function
    using template for the swap operation. Call this function from the Bubble function.
*/

#include <iostream>
using namespace std; 

// template function for bubble sort
template <class T>
void bubbleSort(T a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j])
                swap(a, i, j); 
        }
    }
}

// template function for swap operation
template <class T>
void swap(T a, int position1, int position2) {
    T temp = a[position1]; 
    a[position1] = a[position2]; 
    a[position2] = temp; 
}

// main function
int main() {
    int a[20], noElements; 

    // Taking input in array
    cout << "Enter the number of elements in array: "; 
    cin >> noElements; 
    for(int i = 0; i < noElements; i++) {
        cout << "Enter the element number " << i+1 <<": "; 
        cin >> a[i]; 
    }
    
    // calling bubbleSort function
    bubbleSort(a, noElements); 

    // displaying the array after sorting
    for(int i = 0; i < noElements; i++) {
        cout << a[i] << " "; 
    }

    return 0; 
}
