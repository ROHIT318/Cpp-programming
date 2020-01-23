#include <iostream>

using namespace std;

class str {
	public:
		string data;
		str(string value) {
			data = value;
		}
};

int main() {
	str str1("Rohit"), str2("Cat"); 
	if(str1.data < str2.data) {
		cout << "1";
	}
	else {
		cout << "2";
	}
}
