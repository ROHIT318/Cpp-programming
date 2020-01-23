#include <iostream>
using namespace std; 

class complex
{
    float real; 
    float imaginary; 

    public: 
        complex operator+(complex); 
        complex operator-(complex); 
        complex operator/(complex);  
        complex operator*(complex); 
        void getData(); 
        void displayData(); 
}; 

void complex::getData()
{
    cout << "Enter the real part: "; 
    cin >> real; 
    cout << "Enter the imaginary part: "; 
    cin >> imaginary; 
    cout << endl; 
}

void complex::displayData()
{
    cout << "Complex number is "; 
    cout << real << " + " << imaginary << "i"; 
    cout << endl;  
}

complex complex::operator+(complex c1)
{
    complex c3; 

    c3.real = this->real + c1.real; 
    c3.imaginary = this->imaginary + c1.imaginary; 

    return c3; 
} 

complex complex::operator-(complex c1)
{
    complex c3; 

    c3.real = this->real - c1.real; 
    c3.imaginary = this->imaginary - c1.imaginary; 

    return c3; 
}

complex complex::operator/(complex c1)
{
    complex c3; 

    c3.real = this->real / c1.real; 
    c3.imaginary = this->imaginary / c1.imaginary; 

    return c3; 
}

complex complex::operator*(complex c1)
{
    complex c3; 
    float real, imaginary; 

    c3.real = this->real * c1.real; 
    c3.imaginary = ( this->real * c1.imaginary ) + ( this->imaginary * c1.real ); 
    c3.real = c3.real + ( this->imaginary * c1.imaginary * (-1) ); 

    return c3; 
}

int main()
{
    complex c1,c2,c3; 

    c1.getData(); 
    c2.getData(); 

    c1.displayData(); 
    c2.displayData(); 

    c3 = c1 * c2; 
    cout << "\nAfter multiplication of complex number: "; 
    c3.displayData(); 

    return 0; 
}
