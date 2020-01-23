#include <iostream>
using namespace std; 

class BitOp
{
    private:
        int var1; 
        int var2; 
        int result; 
    
    public:
        BitOp()
        {
            var1 = 0; 
            var2 = 0; 
        }
        BitOp(int number1, int number2)
        {
            var1 = number1; 
            var2 = number2; 
        } 

        void BitAnd(); 
        void BitOr(); 
        void BitXor(); 
        void decToBinary(); 
        int returnBinary(int number); 
        int reverse(int number); 
}; 

void BitOp::BitAnd()
{
    result = var1 & var2; 
}

void BitOp::BitOr()
{
    result = var1 | var2; 
}

void BitOp::BitXor()
{
    result = var1 ^ var2; 
}



void BitOp::decToBinary() 
{ 
	int counter = 0, number; 
    int binaryNum[32]; 
    
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
        while (number > 0)
        { 
            binaryNum[i] = number % 2; 
            number = number / 2; 
            i++; 
        } 
   
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
