#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	const double kEps = 1e-15;

	double a, b, c, xn, xk, dx;
	cout << "Vvedite znachenie a: ";
	cin >> a;
	cout << "Vvedite znachenie b: ";
	cin >> b;
	cout << "Vvedite znachenie c: ";
	cin >> c;
	cout << "Vvedite znachenie xn: ";
	cin >> xn;
	cout << "Vvedite znachenie xk >= xn: ";
	cin >> xk;
	cout << "Vvedite znachenie dx > 0: ";
	cin >> dx;

	if (dx <= 0) {
		cout << "\ndx vveden neverno!!!\n";
		return 1;
	}
	else if (xk < xn) {
		cout << "\nxk vveden neverno!!!\n";
		return 1;
	}

	cout << setw(44) << "| - - - - - - - | - - - - - - - |\n";
	cout << setw(44) << "|       x       |       F       |\n";
	cout << setw(44) << "| - - - - - - - | - - - - - - - |\n";

	cout << fixed;
	cout.precision(3);

	for (double x = xn; x <= xk; x += dx)
	{
		cout << setw(11) << "|" << setw(10) << x << setw(6) << "|";

		double f;
		if ((c < 0) && !(abs(x) < kEps)) {
			f = -a * x - c;
		}
		else if ((c > 0) && (abs(x) < kEps)) {
			f = (x - a) / -c;
		}
		else {
			if (abs(c - a) < kEps) {
				cout << " division by 0 |\n";
				continue;
			}
			else
				f = b * x / (c - a);
		}

		int ac = static_cast<int>(a);
		int bc = static_cast<int>(b);
		int cc = static_cast<int>(c);
		if (ac | bc | cc)
			cout << setw(10) << f << setw(7) << "|\n";
		else
			cout << setw(8) << static_cast<int>(f) << setw(9) << "|\n";

	}
	cout << setw(43) << "| - - - - - - - | - - - - - - - |";

	return 0;
}