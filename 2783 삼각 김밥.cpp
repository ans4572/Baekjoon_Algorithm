#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	double sevenX, sevenY, min;
	cin >> sevenX >> sevenY;
	min = (1000 / sevenY)*sevenX;

	int N;
	double tmpX, tmpY;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> tmpX >> tmpY;
		if (min > ((1000 / tmpY)*tmpX))
			min = (1000 / tmpY)*tmpX;
	}

	//�Ҽ��� 2�ڸ����� ����
	cout << fixed;
	cout.precision(2);

	cout << min << endl;

	return 0;
}