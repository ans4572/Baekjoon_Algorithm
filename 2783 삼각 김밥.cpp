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

	//소수점 2자리까지 고정
	cout << fixed;
	cout.precision(2);

	cout << min << endl;

	return 0;
}