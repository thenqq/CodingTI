#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

// функция для поиска чисел в строке и записи их в сумматор

string sumreg(vector<string> sums, int ks) {
	return 0;
}

// функция для перевода текста в бинарку

string bintext(string& text) {

	string s = text;
	string bintxt = "";
	int asd;
	int t = 0;
	int d = 1;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 48 && s[i] <= 57) {
			cout << s[i];
		}
		else {

			//cout << '<' << (int)(s[i] & 255) << '>' << endl;
			asd = (int)(s[i] & 255);
			t = 0;
			d = 1;
			t += 1 * 10000000;
			while (asd >= 2) {
				t += (asd % 2) * d;
				asd = asd / 2;
				d = d * 10;
			}
			cout << "  " << s[i] << " - <" << t << ">" << endl;
		}
		bintxt = bintxt + to_string(t);
	}
	//cout << bintxt;
	cout << endl;
	return bintxt;
}

int main() {

	// локализация
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// переменные
	int ks, reg;

	reg = 3;

	vector<string> sums;
	vector<int> main;
	string text, buffer, bitext;
	string rezult = "";

	// сколько сумматоров
	cout << "Введите количество сумматоров: ";
	cin >> ks;

	// заполнение регистров нулями
	for (int i = 0; i < reg; i++) {
		main.push_back(0);
	}

	// заполнение регистров для сумматоров
	cout << "\nВведите регистры сумматоров: " << endl;
	for (int i = 0; i < ks + 1; i++) {
		getline(cin, buffer);
		if (buffer.size() > 0) {
			sums.push_back(buffer);
		}
	}


	// текст для кодирования
	cout << "\nВведите текст: ";
	cin >> text;

	// основные расчеты 

	// кодирование 

	bitext = bintext(text);
	cout << "\nbitext - " << bitext << endl;
	cout << "\nsize bitext - " << size(bitext) << endl;
	for (int i = 0; i < size(bitext); i++) {
		char a = bitext[i];
		int aa = a - '0';
		int buf1 = 0;
		int buf2 = 0;
		char rego[] = "";
		size_t len = 0;
		string str;
		main.insert(main.begin(), aa);
		main.pop_back();

		cout << "\nНаши регистры:" << endl;
		for (int q = 0; q < main.size(); q++) {
			cout << "[" << q + 1 << "]" << ": ";
			cout << main[q] << endl;
		}

		cout << "\n цикл - " << i + 1;
		for (int j = 0; j < ks; j++) {
			len = sums[j].size();
			buf1 = 0;
			for (int k = 0; k < len; k++) {
				cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
				cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];
				buf1 = buf1 + main[sums[j][k] - '0' - 1];
			}
			buf1 = buf1 % 2;
			stringstream ss;
			ss << buf1;
			str = ss.str();
			rezult = rezult + str;
		}
	}

	// обнуление
	if (main[0] == 1) {
		for (int i = 0; i < reg; i++) {
			int buf1 = 0;
			size_t len = 0;
			string str;
			main.insert(main.begin(), 0);
			main.pop_back();
			cout << "\nНаши регистры:" << endl;
			for (int q = 0; q < main.size(); q++) {
				cout << "[" << q + 1 << "]" << ": ";
				cout << main[q] << endl;
			}
			for (int j = 0; j < ks; j++) {
				len = sums[j].size();
				buf1 = 0;
				for (int k = 0; k < len; k++) {
					cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
					cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];
					buf1 = buf1 + main[sums[j][k] - '0' - 1];
				}
				buf1 = buf1 % 2;
				stringstream ss;
				ss << buf1;
				str = ss.str();
				rezult = rezult + str;
			}
		}
	}
	else if ((main[0] == 0) && (main[1] == 1)) {
		for (int i = 0; i < reg - 1; i++) {
			int buf1 = 0;
			size_t len = 0;
			string str;
			main.insert(main.begin(), 0);
			main.pop_back();
			cout << "\nНаши регистры:" << endl;
			for (int q = 0; q < main.size(); q++) {
				cout << "[" << q + 1 << "]" << ": ";
				cout << main[q] << endl;
			}
			for (int j = 0; j < ks; j++) {
				len = sums[j].size();
				buf1 = 0;
				for (int k = 0; k < len; k++) {
					cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
					cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];
					buf1 = buf1 + main[sums[j][k] - '0' - 1];
				}
				buf1 = buf1 % 2;
				stringstream ss;
				ss << buf1;
				str = ss.str();
				rezult = rezult + str;
			}
		}
	}
	else {
		for (int i = 0; i < reg - 2; i++) {
			int buf1 = 0;
			size_t len = 0;
			string str;
			main.insert(main.begin(), 0);
			main.pop_back();
			cout << "\nНаши регистры:" << endl;
			for (int q = 0; q < main.size(); q++) {
				cout << "[" << q + 1 << "]" << ": ";
				cout << main[q] << endl;
			}
			for (int j = 0; j < ks; j++) {
				len = sums[j].size();
				buf1 = 0;
				for (int k = 0; k < len; k++) {
					cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
					cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];
					buf1 = buf1 + main[sums[j][k] - '0' - 1];
				}
				buf1 = buf1 % 2;
				stringstream ss;
				ss << buf1;
				str = ss.str();
				rezult = rezult + str;
			}
		}
	}

	cout << "\n Результат кодирования - " << rezult;

	// декодирование витерби


	for (int i = 0; i < size(rezult) / 2; i++) {

		//выделение пары 
		string rezcheck = "";
		string rezb = "";
		string rezb1 = "";
		string rezb2 = "";
		if (i == 0) {
			rezb1 = rezult[i];
			rezb2 = rezult[i + 1];
		}
		else {
			rezb1 = rezult[i * 2];
			rezb2 = rezult[i * 2 + 1];
		}
		rezb = rezb1 + rezb2;
		cout << "\n rezb номер " << i << " - " << rezb;

		// сравнение пары по веткам

		for (int j = 0; j < 2; j++) {

			int buf1 = 0;
			int buf2 = 0;
			char rego[] = "";
			size_t len = 0;
			string str;


			if (j == 0) {
				main.insert(main.begin(), 0);
				main.pop_back();

				cout << "\nНаши регистры:" << endl;
				for (int q = 0; q < main.size(); q++) {
					cout << "[" << q + 1 << "]" << ": ";
					cout << main[q] << endl;
				}
				cout << "\n цикл - " << i + 1;
				for (int j = 0; j < ks; j++) {
					len = sums[j].size();
					buf1 = 0;
					for (int k = 0; k < len; k++) {
						cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
						cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];
						buf1 = buf1 + main[sums[j][k] - '0' - 1];
					}
					buf1 = buf1 % 2;
					stringstream ss;
					ss << buf1;
					str = ss.str();
					rezcheck = rezcheck + str;
				}
			}
			else {

			}
		}

	}

	return 0;
}