#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>
#include <bitset>
#include <stdlib.h>


using namespace std;

// ??????? ??? ?????? ????? ? ?????? ? ?????? ?? ? ????????

string sumreg(vector<string> sums, int ks) {
	return 0;
}

// ???

char binarysymbol(char symb) {
	char s = symb;
	char bintxt;
	int asd, asdf;
	int t = 0;
	int d = 1;

	for (size_t i = 0; i < 1; ++i)
	{
		if (s >= 32 && s <= 63) {
			asd = (int)(s & 255);
			asdf = (int)(s & 255);
			t = 0;
			d = 1;
			t += 1 * 100000;
			while (asd >= 2) {
				t += (asd % 2) * d;
				asd = asd / 2;
				d = d * 10;
			}
			//std::cout << "  " << s << " - <" << t << ">" << endl;
			//indexs.push_back(1);
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
			//std::cout << "  " << s << " - <" << t << ">" << endl;
			//indexs.push_back(2);

		}
		bintxt = t;
	}
	//std::cout << "\n ASCII symb - " << asdf;
	std::cout << endl;
	return bintxt;
}

string gotindex(string txt) {
	string s = txt;
	string ert = "";
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 32 && s[i] <= 63) {
			ert += "1";
		}
		else if (s[i] > 63 && s[i] < 128) {
			ert += "2";
		}
		else {
			ert += "3";
		}
	}
	return ert;
}

// ??????? ??? ???????? ?????? ? ???????

string bintext(string qwe) {

	string s = qwe;
	string bintxt = "";
	int asd, asdf;
	int t = 0;
	int d = 1;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 32 && s[i] <= 63) {
			asd = (int)(s[i] & 255);
			asdf = (int)(s[i] & 255);
			t = 0;
			d = 1;
			t += 1 * 100000;
			while (asd >= 2) {
				t += (asd % 2) * d;
				asd = asd / 2;
				d = d * 10;
			}
			std::cout << "  " << s[i] << " - <" << t << ">" << endl;
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

	// ???????????
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ??????????
	int ks, reg;


	vector<string> sums, binarytext;
	vector<int> main;
	vector<string> indexs;
	string text, buffer, bitext;
	string rezult = "";
	

	// ??????? ?????????
	
	std::cout << "?????????? ?????????: ";
	while (1) {
		string ksc;
		double value;
		std::cout << "\n???? - " << endl;
		std::getline(std::cin, ksc);
		stringstream aksc{ ksc };
		char symbol;
		while (1) {
			symbol = aksc.peek();
			if (symbol == '\377') {
				break;
			}
			if (symbol >= '0' && symbol <= '9') {
				aksc >> value;
				reg = value;
				continue;
			}
			else {
				aksc.ignore();
				continue;
			}
		}
		if (reg != 0) {
			break;
		}
		else {
			std::cout << "\n???????????? ????. ??????? ?????.";
		}
	}
	// ??????? ??????????
	std::cout << "?????????? ??????????: ";
	while (1) {
		string ksc;
		double value;
		std::cout << "\n???? - " << endl;
		std::getline(std::cin, ksc);
		stringstream aksc{ ksc };
		char symbol;
		while (1) {
			symbol = aksc.peek();
			if (symbol == '\377') {
				break;
			}
			if (symbol >= '0' && symbol <= '9') {
				aksc >> value;
				ks = value;
				continue;
			}
			else {
				aksc.ignore();
				continue;
			}
		}
		if (ks != 0) {
			break;
		}
		else {
			std::cout << "\n???????????? ????. ??????? ?????.";
		}
	}
	std::cout << "?????????? ?????????? - " << ks << endl;

	// ?????????? ????????? ??????
	for (int i = 0; i < reg; i++) {
		main.push_back(0);
	}

	// ?????????? ????????? ??? ??????????
	std::cout << "\n??????? ???????? ??????????: " << endl;
	/*for (int i = 0; i < ks; i++) {
		getline(std::cin, buffer);
		if (buffer.size() > 0) {
			sums.push_back(buffer);
		}
	}*/
	for (int i = 0; i < ks; i++) {
		while (1) {
			string ksc;
			double value;
			std::cout << "???? - " << endl;
			std::getline(std::cin, ksc);
			stringstream aksc{ ksc };
			char symbol;
			int qwe = 0;
			while (1) {
				symbol = aksc.peek();
				if (symbol == '\377') {
					break;
				}
				if (symbol >= '0' && symbol <= '9') {
					aksc >> value;
					qwe = value;
					sums.push_back(to_string(qwe));
					continue;
				}
				else {
					aksc.ignore();
					continue;
				}
			}
			if (qwe != 0) {
				break;
			}
			else {
				std::cout << "\n???????????? ????. ??????? ?????.";
			}
		}
	}
	
	std::cout << "\n ?????????:";
	for (int i = 0; i < sums.size(); i++) {
		cout << "\n[" << i << "] - " << sums[i];
	}
	std::cout << endl;

	// ????? ??? ???????????

	std::cout << "\n??????? ?????: ";
	std::getline(std::cin, text);

	// ???????? ??????? 

	// ??????????? 

	bitext = bintext(text);
	string omen = gotindex(text);
	indexs.push_back(omen);

	std::cout << "\n omen - " << indexs[0] << endl;

	std::cout << " ????? ? ??????? - " << bitext << endl;
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

		// ?????????
		if (main[0] == 1) {
			for (int i = 0; i < reg; i++) {
				int buf1 = 0;
				size_t len = 0;
				string str;
				main.insert(main.begin(), 0);
				main.pop_back();
				/*std::cout << "\n???? ????????:" << endl;
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
				/*std::cout << "\n???? ????????:" << endl;
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
				/*std::cout << "\n???? ????????:" << endl;
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
				}
			}
		}

		std::cout << " ????????? ??????????? - " << rezult << endl;

		// ????????????? ???????

		string strokadekodera = "";
		vector<string> dekoder;

		// ???? ?????? ?????? ??? ???? ??????????

		/*for (int p = 0; p < 1; p++) {
			for (int i = 0; i < size(rezult) / 2; i++) {

				//????????? ????
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
				/*std::cout << "\n ???? ????? ????? " << i + 1 << " - " << rezb << endl;

				// ????? ????????? ????? ??????????
				std::cout << "\n???? ???????? ????? ??????????  :" << endl;
				for (int q = 0; q < main.size(); q++) {
					std::cout << "[" << q + 1 << "]" << ": ";
					std::cout << main[q] << endl;
				}

				// ????????? ???? ?? ??????

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

						/*std::cout << "\n???? ???????? + 0 :" << endl;
						for (int q = 0; q < main.size(); q++) {
							std::cout << "[" << q + 1 << "]" << ": ";
							std::cout << main[q] << endl;
						}
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
						//std::cout << "\n ???? ????? ??? ?????????? ? ???????? 0 - " << rezb1 << endl;
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

						/*std::cout << "\n???? ???????? + 1 :" << endl;
						for (int q = 0; q < main.size(); q++) {
							std::cout << "[" << q + 1 << "]" << ": ";
							std::cout << main[q] << endl;
						}
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
						//std::cout << "\n ???? ????? ??? ?????????? ? ???????? 1 - " << rezb2 << endl;
						if (rezb2 != rezb) {
							main.insert(main.begin(), 0);
							main.erase(main.begin() + 1);
						}
						else {
							strokadekodera = strokadekodera + "1";
						}
					}
				}

				/*std::cout << "\n???? ???????? ????? ?????????   :" << endl;
				for (int q = 0; q < main.size(); q++) {
					std::cout << "[" << q + 1 << "]" << ": ";
					std::cout << main[q] << endl;
				}
			}
			size_t phaha = size(strokadekodera);
			int count = 0;
			for (int q = 0; q < size(text); q++) {
				string howtf = "";
				/*cout << "size rez - " << (phaha) << endl;
				cout << "size text - " << size(text) << endl;
				for (int w = (int)phaha / (int)size(text) - 1; w > -1; w--) {
					/*cout << "count - " << count << endl;
					cout << w << endl;
					howtf = howtf + strokadekodera[count];
					count++;
				}
				dekoder.push_back(howtf);
			}
		}*/

		// ??? ???? ??????

		int counttodec = 0;
		//string strokadekodera = "";
		for (int i = 0; i < size(rezult) / ks; i++) {
			string rezb = "";
			string rezb1 = "";
			string rezb2 = "";

			// ????? ?????? ?????????

			for (int j = 0; j < ks; j++) {
				rezb += rezult[counttodec];
				counttodec++;
			}

			//std::cout << "\n ???? <" << i << "> - " << rezb;
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

					/*std::cout << "\n???? ???????? + 0 :" << endl;
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
					//std::cout << "\n ???? ????? ??? ?????????? ? ???????? 0 - " << rezb1 << endl;
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

					/*std::cout << "\n???? ???????? + 1 :" << endl;
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
					//std::cout << "\n ???? ????? ??? ?????????? ? ???????? 1 - " << rezb2 << endl;
					if (rezb2 != rezb) {
						main.insert(main.begin(), 0);
						main.erase(main.begin() + 1);
					}
					else {
						strokadekodera = strokadekodera + "1";
					}
				}
				if (size(rezult) % ks != 0) {

				}
			}


		}
		int count = 0;
		/*for (int w = 0; w < size(text); w++) {
			string howtf = "";
			for (int q = 0; q < ((size(strokadekodera)) / (size(text))); q++) {
				howtf += strokadekodera[count];
				count++;
			}
			dekoder.push_back(howtf);
		}*/

		for (int w = 0; w < size(text); w++) {
			string howtf = "";

			int yuio = omen[w] - '0';
			if (yuio == 2) {
				for (int q = 0; q < 7; q++) {
					howtf += strokadekodera[count];
					count++;
				}
				dekoder.push_back(howtf);
			}
			else if (yuio == 1) {
				for (int q = 0; q < 6; q++) {
					howtf += strokadekodera[count];
					count++;
				}
				dekoder.push_back(howtf);
			}
			else if (yuio == 3) {
				for (int q = 0; q < 8; q++) {
					howtf += strokadekodera[count];
					count++;
				}
				dekoder.push_back(howtf);
			}
		}

		//std::cout << "\n strokadekodera - " << strokadekodera;
		//std::cout << "\n ???????? ????? ? ??????? - " << bitext << endl;
		std::cout << "\n ???????????? ????? ? ??????? - ";
		for (int i = 0; i < dekoder.size(); i++) {
			cout << dekoder[i];
		}
		std::cout << endl;


		std::cout << "\n ?? ??????? ? ASCII - ";
		for (int i = 0; i < dekoder.size(); i++) {
			std::cout << "<" << decoder(dekoder[i]) << "> ";
		}

		std::cout << "\n ??????? ?? ascii ? ????? - ";
		for (int i = 0; i < dekoder.size(); i++) {
			char symbols[255];
			int pqwe = atoi(decoder(dekoder[i]).c_str());
			char asciiChar = static_cast<char>(pqwe);
			std::cout << asciiChar;
		}
		std::cout << endl;
	}

	return 0;
}