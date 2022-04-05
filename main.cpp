#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

// функци€ дл€ поиска чисел в строке и записи их в сумматор

string sumreg(vector<string> sums, int ks) {
	return 0;
}

// функци€ дл€ перевода текста в бинарку

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
	cout << bintxt;
	cout << endl;
	return bintxt;
}

int main() {

	// локализаци€
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// переменные
	int ks, reg;

	reg = 3;

	vector<string> sums;
	vector<int> main, rezz;
	string text, buffer, bitext; 
	string rezult = "";

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
	//sumreg(sums, ks);

	// текст дл€ кодировани€
	cout << "\n¬ведите текст: ";
	cin >> text;

	// основные расчеты 
	bitext = bintext(text);
	cout << "\nbitext - " << bitext << endl;
	cout << "\nsize bitext - " << size(bitext) << endl;
	for (int i = 0; i < size(bitext); i++) {
		char a = bitext[i];
		int aa = a - '0';
		int buf1 = 0;
		int buf2 = 0;
		size_t len = 0;
		string str;
		main.insert(main.begin(), a);
		main.pop_back();
		/*for (int j = 0; j < ks; j++) {
			len = sums[j].size();
			for (int k = 0; k < len; k++) {
				buf1 = buf1 + main[(sums[j][k]) - 1];
			}
			buf1 = buf1 % 2;
			stringstream ss;
			ss << buf1;
			str = ss.str();
		}*/
		for (int j = 0; j < ks; j++) {
			buf1 = main[0] + main[1]; //этот цикл работает верно и ниже тоже вывод верный
		}
		buf1 = buf1 % 2;
		stringstream ss;
		ss << buf1;
		str = ss.str();
		rezult = rezult + str;
		//rezult.push_back(buf1);
		//rezult.push_back(buf2);
	}

	cout << "\nrezult - " << rezult;

	return 0;
}