#include <iostream>

using namespace std; 

class item
{
    private:
        static int count; 
        int number; 

    public:
        void inputNumber(int a)
        {
            number = a; 
            count++; 
        }
        static void getCount()
        {
            cout << "Count:"; 
            cout << count << "\n"; 
        }
        void getNumber()
        {
            cout << "\nNumber:"; 
            cout << number; 
        }
}; 

int item::count; 

int main()
{
    item i1,i2,i3; 

    i1.getCount(); 
    i2.getCount(); 
    i3.getCount(); 

    i1.inputNumber(100); 
    i2.inputNumber(200); 
    i3.inputNumber(300); 

    cout << "\n"; 
    item::getCount(); 

    cout << "\n"; 
    i1.getNumber(); 
    i2.getNumber(); 
    i3.getNumber(); 

    return 0; 
}