#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	const int kMaxIters = 1000000;

	double xn, xk, dx, eps;
	cout << "-1 < x <= 1\n";
	cout << "Vvedite xn: ";
	cin >> xn;
	cout << "Vvedite xk >= xn: ";
	cin >> xk;
	cout << "Vvedite dx > 0: ";
	cin >> dx;
	cout << "Vvedite eps > 0: ";
	cin >> eps;

	if ((xn <= -1) || (xn > xk) || (xk > 1) || (dx <= 0) || (eps <= 0)) {
		cout << "\nWrong input data!\n";
		return 1;
	}

	cout << "| - - - - - - - - | - - - - - - - - ";
	cout << "| - - - - - - - - | - - - - - - - |\n";
	cout << "|        x        |  ln(x+1) (mine) ";
	cout << "| ln(x+1) (cmath) |   iterations  |\n";
	cout << "| - - - - - - - - | - - - - - - - - ";
	cout << "| - - - - - - - - | - - - - - - - |\n";

	cout << fixed;
	cout.precision(6);

	for (; xn <= xk; xn += dx) {
		int n;
		double ln = 0;
		for (n = 0; n <= kMaxIters; n++) {
			double nth_term = pow(-1, n) * pow(xn, n + 1) / (n + 1);
			ln += nth_term;
			if (abs(nth_term) < eps) break;
		}

		cout << "|" << setw(13) << xn << setw(5) << "|";
		if (n <= kMaxIters)
			cout << setw(13) << ln << setw(5);
		else
			cout << " limit exceeded! ";
		cout << "|" << setw(13) << log(xn + 1) << setw(5);
		cout << "|" << setw(9) << n << setw(8) << "|\n";
	}
	cout << "| - - - - - - - - | - - - - - - - - ";
	cout << "| - - - - - - - - | - - - - - - - |";

	return 0;
}