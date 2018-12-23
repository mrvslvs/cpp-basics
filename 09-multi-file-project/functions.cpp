#include "functions.h"

void PrintArray(double *arr, const int kArraySize) {
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << "  ";
	cout << endl;
}

double SumOddElements(double *arr, const int kArraySize) {
	double sum = 0;
	for (int i = 1; i < kArraySize; i += 2)
		sum += arr[i];
	return sum;
}

Negatives FindNegatives(double *arr, const int kArraySize) {
	Negatives negatives;

	for (int i = 0; i < kArraySize; i++)
		if (arr[i] < 0) {
			negatives.first = i;
			break;
		}

	for (int i = kArraySize - 1; i >= 0; i--)
		if (arr[i] < 0) {
			negatives.last = i;
			break;
		}

	return negatives;
}

double GetSumBtFirstLastNegatives(double *arr, Negatives negatives) {
	double sum = 0;
	for (int i = negatives.first + 1; i < negatives.last; i++)
		sum += arr[i];
	return sum;
}

void SqueezeArray(double *arr, const int kArraySize) {
	for (int i = 0; i < kArraySize; i++)
		if (abs(arr[i]) <= 1)
			arr[i] = 0;

	for (int i = 0; i < kArraySize - 1; i++)
		for (int j = 0; j < kArraySize - i - 1; j++)
			if (arr[j] == 0) {
				arr[j] = arr[j + 1];
				arr[j + 1] = 0;
			}
}