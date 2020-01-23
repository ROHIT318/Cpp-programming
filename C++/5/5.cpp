/*  Design a class complex having two float type data members real and imaginary representing the real and
    imaginary parts of a complex number respectively. Write suitable constructors to set the values of the
    objects. Overload the +, -, * and / operators to perform addition, subtraction, mulplication and
    division operations respectively on the complex objects.
*/

#include <iostream>
using namespace std; 

class complex
{
    // declaration of data meembers privately
    float real; 
    float imaginary; 

    public: 
    // need constructor declaration and overloading
        complex operator+(complex); 
        complex operator-(complex); 
        complex operator/(complex);  
        complex operator*(complex); 
        void getData(); 
        void displayData(); 
}; 
// taking input
void complex::getData()
{
    cout << "Enter the real part: "; 
    cin >> real; 
    cout << "Enter the imaginary part: "; 
    cin >> imaginary; 
    cout << endl; 
}
// displaying the complex number
void complex::displayData()
{
    cout << "Complex number is "; 
    cout << real << " + " << imaginary << "i"; 
    cout << endl;  
}
// overloading "+" operator
complex complex::operator+(complex c1)
{
    complex c3; 

    c3.real = this->real + c1.real; 
    c3.imaginary = this->imaginary + c1.imaginary; 

    return c3; 
} 
// overloading "-" operator
complex complex::operator-(complex c1)
{
    complex c3; 

    c3.real = this->real - c1.real; 
    c3.imaginary = this->imaginary - c1.imaginary; 

    return c3; 
}
// overloading "/" operator
complex complex::operator/(complex c1)
{
    complex c3; 

    c3.real = this->real / c1.real; 
    c3.imaginary = this->imaginary / c1.imaginary; 

    return c3; 
}
// overloading "*" operator
complex complex::operator*(complex c1)
{
    complex c3; 
    float real, imaginary; 

    c3.real = this->real * c1.real; 
    c3.imaginary = ( this->real * c1.imaginary ) + ( this->imaginary * c1.real ); 
    c3.real = c3.real + ( this->imaginary * c1.imaginary * (-1) ); 

    return c3; 
}
// main function needs to be modified using infinite while and switch cases
int main()
{
    complex c1,c2,c3; 
    // taking input
    c1.getData(); 
    c2.getData(); 
    // displaying data
    c1.displayData(); 
    c2.displayData(); 

    c3 = c1 * c2; 
    cout << "\nAfter multiplication of complex number: "; 
    c3.displayData(); 

    return 0; 
}
