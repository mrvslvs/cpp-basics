#include <iostream>

using namespace std;

struct Negatives {
	int first = -1;
	int last = -1;
};

void PrintArray(double *arr, const int kArraySize);
double SumOddElements(double *arr, const int kArraySize);
Negatives FindNegatives(double *arr, const int kArraySize);
double GetSumBtFirstLastNegatives(double *arr, Negatives negatives);
void SqueezeArray(double *arr, const int kArraySize);

int main() {
	const int kArraySize = 10;
	double arr[kArraySize] = { 8, -1, .4, -2, 0, .1, 6, .3, -9, 5 };

	cout << "Initial array:\n";
	PrintArray(arr, kArraySize);

	cout << "\nSumma nechetnich elementov massiva: ";
	cout << SumOddElements(arr, kArraySize);
	cout << endl;

	Negatives negatives = FindNegatives(arr, kArraySize);

	if ((negatives.first > -1) && (negatives.first < negatives.last)) {
		if (negatives.first + 1 == negatives.last) {
			cout << "\nPervij i poslednij elementi ryadom dryg s drygom.";
		}
		else {
			cout << "\nSumma mejdu pervim i poslednim otricatel'nimi elementami: ";
			cout << GetSumBtFirstLastNegatives(arr, negatives);
		}
	}
	else {
		cout << "\nNo two negative elements were found.";
	}
	cout << endl;

	cout << "\nSqueezed array:\n";
	SqueezeArray(arr, kArraySize);
	PrintArray(arr, kArraySize);

	return 0;
}

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