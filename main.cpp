#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

	// �����������
	setlocale(LC_ALL, "");

	// ����������
	int ks, reg;

	reg = 3;

	vector<string> sums;
	vector<int> main;
	string text, buffer;

	// ������� ����������
	cout << "������� ���������� ����������: ";
	cin >> ks;

	// ���������� ��������� ������
	for (int i = 0; i < reg; i++) {
		main.push_back(0);
	}

	// ���������� ��������� ��� ����������
	cout << "\n������� �������� ����������: " << endl;
	for (int i = 0; i < ks + 1; i++) {
		getline(cin, buffer);
		if (buffer.size() > 0) {
			sums.push_back(buffer);
		}
	}

	// ����� ��� �����������
	cout << "\n������� �����: ";
	cin >> text;



	return 0;
}