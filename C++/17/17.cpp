#include <iostream>

using namespace std; 

class mydate {
	public: 
		int date; 
		int month; 
		int year; 
		
		void input_date(int dd, int mm, int yyyy) {
			switch(mm) {
				case 1: 
				case 3: 
				case 5: 
				case 7: 
				case 9: 
				case 11: 
					if (dd >= 1 && dd <=31) {
						date = dd; 
					} 
					else {
						cout << "Wrong date given."; 
						exit(1); 
					}
				break; 
				case 2: 
					if ((yyyy % 4) == 0) {
						if (dd <= 29) {
							date = dd; 
						}
						else {
							cout << "Wrong date given."; 
							exit(1); 
						}
					}
					else {
						if (dd <= 28) {
							date = dd; 
						}
						else {
							cout << "Wrong date given."; 
							exit(1); 
						}
					}
				break; 
				case 4: 
				case 6: 
				case 8: 
				case 10:
				case 12: 
					if (dd >= 1 && dd <=30) {
						date = dd; 
					} 
					else {
						cout << "Wrong date given."; 
						exit(1); 
					}
				break; 
				default: 
					cout << "Wrong month given."; 
					exit(1); 
			}
			month = mm; 
			year = yyyy; 
		}

		void next_day() {
			if (date >= 1 && date < 28) {
				date++; 
			}
			else if (month == 2 && date == 28) {
				if ((year % 4) == 0) {
					date++; 
				}
				else {
					date = 1; 
					month++; 
				} 
			}
			else if (month == 2 && date == 29) {
				date = 1; 
				month++; 
			}
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
				if (date < 31)
					date++; 
				else {
					date = 1; 
					month++; 
				}
			}
			else if (month == 4 || month == 6 || month == 8 || month == 10) {
				if (date < 30) 
					date++; 
				else {
					date = 1; 
					month++; 
				}
			}
			else if (month == 12) {
				if (date == 30) {
					date = 1; 
					month = 1; 
					year++; 
				}
			}
		}

		void previous_day() {
			if (date > 1 && date <= 31) {
				date--; 
			}
			else {
				if (month == 5 || month == 7 || month == 9 || month == 11) {
					date = 30; 
					month--; 
				}
				else if (month == 2 || month == 4 || month == 6 || month == 8 || month == 10 || month == 12) {
					date = 31; 
					month--; 
				}
				else if (month == 1) {
					date = 30; 
					month = 12; 
					year--; 
				}
				else if (month == 3) {
					month--; 
					if((year % 4) == 0) {
						date = 29; 
					}
					else {
						date = 28; 
					}
				}
			}
		}

		void compare_date(mydate &obj) {
			if (date == obj.date && month == obj.month && year == obj.year)
				return 1; 
			else
				return 0; 
		}

		void display_date() {
			cout << endl << endl; 
			cout << "Date is " << date << "/" << month << "/" << year; 
			cout << endl << endl; 
		}
};

int main() {
	mydate date; 
	int date, month, year; 

	cout << "Enter date: "; 
	cin >> date; 
	cout << "Enter month: "; 
	cin >> month; 
	cout << "Enter year: "; 
	cin >> year; 
	date.input_date(date, month, year); 

	date.display_date(); 

	while(1) {
		cout << "Press 1 for getting the next day.\n"; 
		cout << "Press 2 for getting the previous day.\n"; 
		cout << "Press 3 for comparing two dates.\n"; 
		cout << "Press 4 for exit.\n"; 
		int input; 
		cout << "Enter input: "; 
		cin >> input; 
		switch(input) {
			case 1: 
				date.next_day(); 
				date.display_date(); 
			break; 
			case 2: 
				date.previous_day(); 
				date.display_date(); 
			break; 
			case 3: 
				mydate date_two; 
				int date_two, month_two, year_two, check; 

				cout << "Enter date: "; 
				cin >> date_two; 
				cout << "Enter month: "; 
				cin >> month_two; 
				cout << "Enter year: "; 
				cin >> year_two; 
				date.input_date(date_two, month_two, year_two); 

				check = date.compare_date(date_two); 
				cout << endl; 
				if (check == 1)
					cout << "Date are same."; 
				else
					cout << "Date are different."; 
			break; 
			case 4: 
				exit(1); 
			break; 
			default: 
				cout << "Wrong input"; 
		}
	}
	
	return 0; 
}
