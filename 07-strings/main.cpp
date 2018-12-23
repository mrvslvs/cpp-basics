#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("text.txt");
	if (!fin.is_open()) {
		cout << "Error! Can't open file: \"text.txt\".\n";
		return 1;
	}

	char vowels[] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
	cout << "Slova nachinaushiesya s glasnih bukv: \n";

	string line;
	while (getline(fin, line)) {
		for (unsigned int i = 0; i < line.length(); i++)
			if (find(vowels, vowels + 10, line[i]) != (vowels + 10))
				if ((i == 0) || ((i > 0) && (line[i - 1] == ' '))) {
					while (isalpha(line[i]))
						cout << line[i++];
					cout << endl;
				}
	}

	fin.close();

	return 0;
}