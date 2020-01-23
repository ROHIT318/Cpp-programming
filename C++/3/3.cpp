/*  Design a class BitOp containing two integer data members. The class should contain methods like BitAnd,
	BitOr and BitXor to do bitwise AND, bitwise OR, and bitwise XOR operations respectively on the data
	members of the objects. Write suitable constructors for inializing the objects. Write a display funcons to
	show the results in binary form.
*/

#include <iostream>
using namespace std; 

class BitOp
{
    private:
		// Declaring data members as private
        int var1; 
        int var2; 
        int result; 
    
    public:
		// constructor declaration
        BitOp()
        {
            var1 = 0; 
            var2 = 0; 
        }
		// constructor overloading
        BitOp(int number1, int number2)
        {
            var1 = number1; 
            var2 = number2; 
        } 

		// all member function declaration
        void BitAnd(); 
        void BitOr(); 
        void BitXor(); 
        void decToBinary(); 
        // int returnBinary(int number); 
        // int reverse(int number); 
}; 

// performing bitwise AND operation
void BitOp::BitAnd()
{
    result = var1 & var2; 
}

// performing bitwise OR operation
void BitOp::BitOr()
{
    result = var1 | var2; 
}

// performing bitwise XOR operation
void BitOp::BitXor()
{
    result = var1 ^ var2; 
}


// converting decimal to binary number
void BitOp::decToBinary() 
{ 
	int counter = 0, number; 
    int binaryNum[32]; 
    // Due to 4 bit integer counter counting from 0 to 3
    while(counter < 3)
    { 
        if(counter == 0)
        {
            number = var1; 
            cout << "First number is "; 
        }
        else if(counter == 1)
        {
            number = var2; 
            cout << "Second number is "; 
        }
        else
        {
            number = result; 
            cout << "Result is "; 
        }
        int i = 0; 
		// storing the remainders in an array after dividing by 2
        while (number > 0)
        { 
            binaryNum[i] = number % 2; 
            number = number / 2; 
            i++; 
        } 
   		// displaying the array in rverse manner
        for (int j = i - 1; j >= 0; j--) 
        {
            cout << binaryNum[j]; 
        }
        cout << endl; 
        counter++; 
    }
} 

int main()
{
    BitOp bits(13,12); 

    bits.BitAnd(); 
    cout << " **Result after AND operation**" << endl; 
    bits.decToBinary(); 

    cout << endl << endl; 
    bits.BitOr(); 
    cout << " **Result after OR operation**" << endl; 
    bits.decToBinary();  

    cout << endl << endl; 
    bits.BitXor(); 
    cout << " **Result after OR operation**" << endl; 
    bits.decToBinary();  

    return 0; 
}
