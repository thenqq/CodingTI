#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

	// локализаци€
	setlocale(LC_ALL, "");

	// переменные
	int ks, reg;

	reg = 3;

	vector<string> sums;
	vector<int> main;
	string text, buffer;

	// сколько сумматоров
	cout << "¬ведите количество сумматоров: ";
	cin >> ks;

	// заполнение регистров нул€ми
	for (int i = 0; i < reg; i++) {
		main.push_back(0);
	}

	// заполнение регистров дл€ сумматоров
	cout << "\n¬ведите регистры сумматоров: " << endl;
	for (int i = 0; i < ks + 1; i++) {
		getline(cin, buffer);
		if (buffer.size() > 0) {
			sums.push_back(buffer);
		}
	}

	// текст дл€ кодировани€
	cout << "\n¬ведите текст: ";
	cin >> text;



	return 0;
}