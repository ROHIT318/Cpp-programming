#include <iostream>

using namespace std; 

class overloading
{
    private:
        int i,j; 
    public:
        void storeData(int m)
        {
            i = j = m; 
        }
        void storeData(int n,int m)
        {
            i = n; 
            j = m; 
        }
        void showData()
        {
            cout << "\n";  
            cout << "i : " << i << ", " << "j : " << j;  
            cout << "\n"; 
        }
}; 

int main()
{
    overloading o1,o2; 

    o1.storeData(1); 
    o2.storeData(2); 
    o1.showData(); 
    o2.showData(); 

    o1.storeData(1,2); 
    o2.storeData(2,3); 
    o1.showData(); 
    o2.showData(); 

    return 0; 
}