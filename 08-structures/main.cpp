#include <iostream>
#include <string>

using namespace std;

struct Aeroflot {
	string destanation, plane_type;
	int flight_number;
};

int main() {
	const int kNumPlanes = 7;
	Aeroflot planes[kNumPlanes];

	for (int i = 0; i < kNumPlanes; i++) {
		cout << "Vvedite tip samoleta " << i + 1 << ": ";
		getline(cin, planes[i].plane_type);

		cout << "Vvedite nomer samoleta: ";
		cin >> planes[i].flight_number;
		cin.ignore();

		cout << "Vvedite destanation: ";
		getline(cin, planes[i].destanation);

		cout << endl;
	}

	for (int i = 0; i < kNumPlanes - 1; i++)
		for (int j = 0; j < kNumPlanes - i - 1; j++)
			if (planes[j].flight_number > planes[j + 1].flight_number)
				swap(planes[j], planes[j + 1]);

	for (int i = 0; i < kNumPlanes; i++) {
		cout << "Plane " << planes[i].plane_type;
		cout << " number " << planes[i].flight_number;
		cout << " is flying to " << planes[i].destanation;
		cout << endl;
	}

	string destanation;
	cout << "\nVvedite naznachenie: ";
	getline(cin, destanation);
	cout << endl;

	bool no_flights = true;
	for (int i = 0; i < kNumPlanes; i++) {
		if (planes[i].destanation == destanation) {
			no_flights = false;
			cout << "Vam podhodit ";
			cout << planes[i].plane_type << " plane ";
			cout << "number " << planes[i].flight_number;
			cout << endl;
		}
	}

	if (no_flights)
		cout << "Vam ne podhodit ni odit samolet.";

	return 0;
}