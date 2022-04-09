#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>
#include <bitset>
#include <stdlib.h>


using namespace std;

// функция для поиска чисел в строке и записи их в сумматор

string sumreg(vector<string> sums, int ks) {
	return 0;
}

// фыв

char binarysymbol(char symb) {
	char s = symb;
	char bintxt;
	int asd, asdf;
	int t = 0;
	int d = 1;

	for (size_t i = 0; i < 1; ++i)
	{
		if (s >= 48 && s <= 57) {
			std::cout << s;
		}
		else {
			asd = (int)(s & 255);
			asdf = (int)(s & 255);
			t = 0;
			d = 1;
			if (asd >= 128) {
				t += 1 * 10000000;
			}
			else {
				t += 1 * 1000000;
			}
			while (asd >= 2) {
				t += (asd % 2) * d;
				asd = asd / 2;
				d = d * 10;
			}
		}
		bintxt = t;
	}
	//std::cout << "\n ASCII symb - " << asdf;
	std::cout << endl;
	return bintxt;
}

// функция для перевода текста в бинарку

string bintext(string qwe) {

	string s = qwe;
	string bintxt = "";
	int asd, asdf;
	int t = 0;
	int d = 1;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 48 && s[i] <= 57) {
			std::cout << s[i];
		}
		else {
			asd = (int)(s[i] & 255);
			asdf = (int)(s[i] & 255);
			t = 0;
			d = 1;
			if (asd >= 128) {
				t += 1 * 10000000;
			}
			else {
				t += 1 * 1000000;
			}
			while (asd >= 2) {
				t += (asd % 2) * d;
				asd = asd / 2;
				d = d * 10;
			}
			std::cout << "  " << s[i] << " - <" << t << ">" << endl;
		}
		bintxt = bintxt + to_string(t);
		std::cout << "ASCII symb - " << asdf << endl;
	}
	
	std::cout << endl;
	return bintxt;
}

// decoder

string decoder(string strokadekodera) {

	string rezz;
	string binf = "";
	int n = size(strokadekodera);
	int sum = 0;
	int what = 0;

	for (int i = n; i > -1; i--) {
		binf = binf + strokadekodera[i];
	}
	for (int i = size(binf) - 1; i > -1; i--) {
		if (binf[i] == '1') {
			sum += pow(2, i - 1);
			what = pow(2, i);
		}
	}
	rezz = to_string(sum);

	return rezz;
}

int main() {

	// локализация
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// переменные
	int ks, reg;

	reg = 3;

	vector<string> sums, binarytext;
	vector<int> main;
	string text, buffer, bitext;
	string rezult = "";

	// сколько сумматоров
	std::cout << "Введите количество сумматоров: ";
	cin >> ks;

	// заполнение регистров нулями
	for (int i = 0; i < reg; i++) {
		main.push_back(0);
	}

	// заполнение регистров для сумматоров
	std::cout << "\nВведите регистры сумматоров: " << endl;
	for (int i = 0; i < ks + 1; i++) {
		getline(cin, buffer);
		if (buffer.size() > 0) {
			sums.push_back(buffer);
		}
	}


	// текст для кодирования
	std::cout << "\nВведите текст: ";
	cin >> text;

	// основные расчеты 

	// кодирование 

	bitext = bintext(text);
	std::cout << "\n Текст в бинарке - " << bitext << endl;

	for (int u = 0; u < 1; u++) {

		char symboltobi;
		symboltobi = binarysymbol(text[u]);
		string bisymbol;

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

			for (int j = 0; j < ks; j++) {
				len = sums[j].size();
				buf1 = 0;
				for (int k = 0; k < len; k++) {
					/*std::cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
					std::cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];*/
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
				/*std::cout << "\nНаши регистры:" << endl;
				for (int q = 0; q < main.size(); q++) {
					std::cout << "[" << q + 1 << "]" << ": ";
					std::cout << main[q] << endl;
				}*/
				for (int j = 0; j < ks; j++) {
					len = sums[j].size();
					buf1 = 0;
					for (int k = 0; k < len; k++) {
						/*std::cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
						std::cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];*/
						buf1 = buf1 + main[sums[j][k] - '0' - 1];
					}
					buf1 = buf1 % 2;
					stringstream ss;
					ss << buf1;
					str = ss.str();
					//rezult = rezult + str;
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
				/*std::cout << "\nНаши регистры:" << endl;
				for (int q = 0; q < main.size(); q++) {
					std::cout << "[" << q + 1 << "]" << ": ";
					std::cout << main[q] << endl;
				}*/
				for (int j = 0; j < ks; j++) {
					len = sums[j].size();
					buf1 = 0;
					for (int k = 0; k < len; k++) {
						/*std::cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
						//std::cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];*/
						buf1 = buf1 + main[sums[j][k] - '0' - 1];
					}
					buf1 = buf1 % 2;
					stringstream ss;
					ss << buf1;
					str = ss.str();
					//rezult = rezult + str;
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
				/*std::cout << "\nНаши регистры:" << endl;
				for (int q = 0; q < main.size(); q++) {
					std::cout << "[" << q + 1 << "]" << ": ";
					std::cout << main[q] << endl;
				}*/
				for (int j = 0; j < ks; j++) {
					len = sums[j].size();
					buf1 = 0;
					for (int k = 0; k < len; k++) {
						/*std::cout << "\n sums[" << j << "][" << k << "] - " << sums[j][k];
						std::cout << "\n main[sums[" << j << "][" << k << "] - '0' - 1] - " << main[sums[j][k] - '0' - 1];*/
						buf1 = buf1 + main[sums[j][k] - '0' - 1];
					}
					buf1 = buf1 % 2;
					stringstream ss;
					ss << buf1;
					str = ss.str();
					//rezult = rezult + str;
				}
			}
		}

		std::cout << "\n Результат кодирования - " << rezult << endl;

		// декодирование витерби

		string strokadekodera = "";
		vector<string> dekoder;
		for (int p = 0; p < 1; p++) {
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
				//std::cout << "\n Пара битов номер " << i + 1 << " - " << rezb << endl;

				// вывод регистров перед сравнением 
				/*std::cout << "\nНаши регистры перед сравнением  :" << endl;
				for (int q = 0; q < main.size(); q++) {
					std::cout << "[" << q + 1 << "]" << ": ";
					std::cout << main[q] << endl;
				}*/

				// сравнение пары по веткам

				for (int j = 0; j < 2; j++) {

					int buf1 = 0;
					int buf2 = 0;
					size_t len = 0;
					string str = "";

					if (j == 0) {
						string rezb1 = "";
						string str = "";
						main.insert(main.begin(), 0);
						main.pop_back();

						/*std::cout << "\nНаши регистры + 0 :" << endl;
						for (int q = 0; q < main.size(); q++) {
							std::cout << "[" << q + 1 << "]" << ": ";
							std::cout << main[q] << endl;
						}*/
						for (int j = 0; j < ks; j++) {
							len = sums[j].size();
							buf1 = 0;
							for (int k = 0; k < len; k++) {
								buf1 = buf1 + main[sums[j][k] - '0' - 1];
							}
							buf1 = buf1 % 2;
							stringstream ss;
							ss << buf1;
							str = ss.str();
							rezb1 = rezb1 + str;
						}
						main.insert(main.begin(), 0);
						main.erase(main.begin() + 1);
						//std::cout << "\n Пара битов при добавление в регистры 0 - " << rezb1 << endl;
						if (rezb1 != rezb) {
							main.insert(main.begin(), 0);
							main.erase(main.begin() + 1);
						}
						else {
							j++;
							strokadekodera = strokadekodera + "0";

						}
					}
					else {
						string rezb2 = "";
						string str = "";
						main.insert(main.begin(), 1);
						main.erase(main.begin() + 1);

						/*std::cout << "\nНаши регистры + 1 :" << endl;
						for (int q = 0; q < main.size(); q++) {
							std::cout << "[" << q + 1 << "]" << ": ";
							std::cout << main[q] << endl;
						}*/
						for (int j = 0; j < ks; j++) {
							len = sums[j].size();
							buf1 = 0;
							for (int k = 0; k < len; k++) {
								buf1 = buf1 + main[sums[j][k] - '0' - 1];
							}
							buf1 = buf1 % 2;
							stringstream ss;
							ss << buf1;
							str = ss.str();
							rezb2 = rezb2 + str;
						}
						//std::cout << "\n Пара битов при добавление в регистры 1 - " << rezb2 << endl;
						if (rezb2 != rezb) {
							main.insert(main.begin(), 0);
							main.erase(main.begin() + 1);
						}
						else {
							strokadekodera = strokadekodera + "1";
						}
					}
				}

				/*std::cout << "\nНаши регистры после сравнения   :" << endl;
				for (int q = 0; q < main.size(); q++) {
					std::cout << "[" << q + 1 << "]" << ": ";
					std::cout << main[q] << endl;
				}*/
			}
			size_t phaha = size(strokadekodera);
			int count = 0;
			for (int q = 0; q < size(text); q++) {
				string howtf = "";
				/*cout << "size rez - " << (phaha) << endl;
				cout << "size text - " << size(text) << endl;*/
				for (int w = (int)phaha / (int)size(text) - 1; w > -1; w--) {
					/*cout << "count - " << count << endl;
					cout << w << endl;*/
					howtf = howtf + strokadekodera[count];
					count++;
				}
				dekoder.push_back(howtf);
			}
		}

		std::cout << "\n Исходный текст в бинарке - " << bitext;
		std::cout << "\n Декодируемый текст в бинарке - ";
		for (int i = 0; i < dekoder.size(); i++) {
			cout << dekoder[i];
		}

		std::cout << "\n Из бинарки в ASCII - ";
		for (int i = 0; i < dekoder.size(); i++) {
			std::cout << "<" << decoder(dekoder[i]) << "> ";
		}

		std::cout << "\n Циферки из ascii в текст - ";
		for (int i = 0; i < dekoder.size(); i++) {
			char symbols[255];
			int pqwe = atoi(decoder(dekoder[i]).c_str());
			char asciiChar = static_cast<char>(pqwe);
			std::cout << asciiChar;

		}


		

		//int pqwe = atoi(decoder(strokadekodera).c_str());

		//char asciiChar = static_cast<char>(pqwe);

		//strcpy_s(symbols, decoder(strokadekodera).c_str());
		//std::cout << "\nCимвол из ascii в текст - " << asciiChar << endl;
	}


	return 0;
}