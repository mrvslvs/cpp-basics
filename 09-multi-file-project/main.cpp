#include "functions.h"

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