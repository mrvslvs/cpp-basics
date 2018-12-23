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