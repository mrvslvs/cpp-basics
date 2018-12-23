#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

bool ReadMatrix(int **matrix, int size, string file_name);
void PrintMatrix(int **matrix, int size);
void MultNonNegativeRows(int **matrix, int size);
int MaxDiagonalSum(int **matrix, int size);

int main() {
	int size;
	cout << "Enter razmernost' matrizy: ";
	cin >> size;

	int **matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	if (!ReadMatrix(matrix, size, "matrix.txt"))
		return 1;

	PrintMatrix(matrix, size);
	cout << endl;

	MultNonNegativeRows(matrix, size);
	cout << endl;

	cout << " Max sum of diagonals in matrix: ";
	cout << MaxDiagonalSum(matrix, size) << endl;

	for (int i = 0; i < size; i++) delete[] matrix[i];
	delete[] matrix;

	return 0;
}

bool ReadMatrix(int **matrix, int size, string file_name) {
	ifstream fin(file_name);
	if (!fin.is_open()) {
		cout << "Can't open file: " << file_name << endl;
		return 0;
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			fin >> matrix[i][j];

	fin.close();
	return 1;
}

void PrintMatrix(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}
}

void MultNonNegativeRows(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		bool negative_elements_in_row = false;
		int product = 1;
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] >= 0) {
				product *= matrix[i][j];
			}
			else {
				negative_elements_in_row = true;
				break;
			}
		}

		if (!negative_elements_in_row) {
			cout << " Proizvedenie stroki: " << i + 1;
			cout << " = " << product << endl;
		}
	}
}

int MaxDiagonalSum(int **matrix, int size) {
	// Main diagonal.
	int max_sum = 0;
	for (int i = 0; i < size; i++)
		max_sum += matrix[i][i];

	// Remaining diagonals.
	for (int i = 1; i < size; i++) {
		int sum_below_main = 0, sum_above_main = 0;
		for (int j = 0, k = j; j < size - i; j++, k++) {
			sum_below_main += matrix[j + i][k];
			sum_above_main += matrix[j][k + i];
		}

		if (sum_below_main > max_sum)
			max_sum = sum_below_main;
		if (sum_above_main > max_sum)
			max_sum = sum_above_main;
	}
	return max_sum;
}