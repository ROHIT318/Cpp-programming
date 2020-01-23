#include <iostream>
#define m 10
#define n 10

using namespace std; 

class mat {
	public:
		int matrix[m][n]; 
		int no_rows, no_columns; 
		
		mat() {
		}
		
		mat(int first, int second) {
			no_rows = first; 
			no_columns = second; 
		}
		
		void input_matrix() {
			cout << "Enter the number of rows: "; 
			cin >> no_rows; 
			cout << "Enter the number of columns: "; 
			cin >> no_columns; 
			for(int i = 0; i < no_rows; i++) {
				for(int j = 0; j < no_columns; j++) {
					cout << "Enter the element of " << i + 1 << ", " << j + 1 << " :"; 
					cin >> matrix[i][j]; 
				}
			}
		}
		
		void display_matrix() {
			cout << "The matrix is : " << endl; 
			for(int i = 0; i < no_rows; i++) {
				for(int j = 0; j < no_columns; j++) {
					cout << matrix[i][j]; 
					cout << " "; 
				}
				cout << endl; 
			}
		}
		
		mat operator+(mat &obj) {
			int row_one = this->no_rows; 
			int column_one = this->no_columns; 
			int row_two = obj.no_rows; 
			int column_two = obj.no_columns; 
			mat result_matrix(row_one, column_one); 
			
			if (  row_one == row_two && column_one == column_two ) {
				for(int i = 0; i < row_one; i++) {
					for(int j = 0; j < row_two; j++) {
						result_matrix.matrix[i][j] = this->matrix[i][j] + obj.matrix[i][j]; 
					}
				}
				return result_matrix; 
			}
			else {
				cout << endl; 
				cout << "Addition not possible."; 
				cout << endl; 
			}
		}
		
		mat operator-(mat &obj) {
			int row_one = this->no_rows; 
			int column_one = this->no_columns; 
			int row_two = obj.no_rows; 
			int column_two = obj.no_columns; 
			mat result_matrix(row_one, column_one); 
			
			if (  row_one == row_two && column_one == column_two ) {
				for(int i = 0; i < row_one; i++) {
					for(int j = 0; j < row_two; j++) {
						result_matrix.matrix[i][j] = this->matrix[i][j] - obj.matrix[i][j]; 
					}
				}
				return result_matrix; 
			}
			else {
				cout << endl; 
				cout << "Addition not possible."; 
				cout << endl; 
			}
		}
		
		mat operator*(mat &obj) {
			int row_one = this->no_rows; 
			int column_one = this->no_columns; 
			int row_two = obj.no_rows; 
			int column_two = obj.no_columns; 
			mat result_matrix(row_one, column_two); 
			int sum = 0; 
			
			if (column_one == column_two) {
				for (int i = 0; i < row_one; i++) {
					for (int j = 0; j < column_two; j++) {
						sum = 0; 
						for (int k = 0; k < row_two; k++) {
							sum += this->matrix[i][k] * obj.matrix[k][j]; 
						}
						result_matrix.matrix[i][j] = sum; 
					}
				}
				return result_matrix; 
			}
			else {
				cout << endl; 
				cout << "Multiplication not possible."; 
				cout << endl; 
			}
		}
};

int main() {
	mat matrix_a, matrix_b, matrix_c; 

	cout << "Enter the first matrix: "; 
	cout << endl; 
	matrix_a.input_matrix(); 
	
	cout << "Enter the second matrix: "; 
	cout << endl; 
	matrix_b.input_matrix(); 
	
	cout << endl << endl; 
	cout << "**Displaying both matrix**"; 
	cout << endl; 
	
	cout << "First matrix is :"; 
	cout << endl; 
	matrix_a.display_matrix(); 
	cout << "Second matrix is :"; 
	cout << endl; 
	matrix_b.display_matrix(); 
	
	while(1) {
		int menu_input; 
		cout << "Press 1 for addition of matrix." << endl; 
		cout << "Press 2 for subtraction of matrix." << endl; 
		cout << "Press 3 for multiplication of matrix." << endl; 
		cout << "Press 4 for exit." << endl; 
		cout << "Enter output: "; 
		cin >> menu_input; 
		
		switch(menu_input) {
			case 1: 
				matrix_c = matrix_a + matrix_b; 
				matrix_c.display_matrix(); 
			break; 
			case 2: 
				matrix_c = matrix_a - matrix_b; 
				matrix_c.display_matrix(); 
			break; 
			case 3: 
				matrix_c = matrix_a * matrix_b; 
				matrix_c.display_matrix(); 
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
