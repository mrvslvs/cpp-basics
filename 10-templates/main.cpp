#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

template <class T>
bool ReadMatrix(T **matrix, int size, string file_name);

template <class T>
void PrintMatrix(T **matrix, int size);

template <class T>
void MultNonNegativeRows(T **matrix, int size);

template <class T>
T MaxDiagonalSum(T **matrix, int size);

template <class T>
int Execute(string file_name);

int main() {
	string typedata;
	cout << "what data type do you want to use?\n";
	cout << "1-int, 2-float, 3-double\n";
	cin >> typedata;

	if (typedata == "1") {
		Execute<int>("int.txt");
	}
	else if (typedata == "2") {
		Execute<float>("float.txt");
	}
	else if (typedata == "3") {
		Execute<double>("double.txt");
	}
	else {
		cout << "Error type!";
		return 1;
	}
	return 0;
}

template <class T>
int Execute(string file_name) {
	int size;
	cout << "Enter razmernost' matrizy: ";
	cin >> size;

	T **matrix = new T*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new T[size];

	if (!ReadMatrix(matrix, size, file_name))
		return 1;

	PrintMatrix(matrix, size);
	cout << endl;

	cout << fixed;
	MultNonNegativeRows(matrix, size);
	cout << endl;

	cout << " Max sum of diagonals in matrix: ";
	cout << MaxDiagonalSum(matrix, size) << endl;

	for (int i = 0; i < size; i++) delete[] matrix[i];
	delete[] matrix;

	return 0;
}

template <class T>
bool ReadMatrix(T **matrix, int size, string file_name) {
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

template <class T>
void PrintMatrix(T **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}
}

template <class T>
void MultNonNegativeRows(T **matrix, int size) {
	for (int i = 0; i < size; i++) {
		bool negative_elements_in_row = false;
		T product = 1;
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

template <class T>
T MaxDiagonalSum(T **matrix, int size) {
	// Main diagonal.
	T max_sum = 0;
	for (int i = 0; i < size; i++)
		max_sum += matrix[i][i];

	// Remaining diagonals.
	for (int i = 1; i < size; i++) {
		T sum_below_main = 0, sum_above_main = 0;
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