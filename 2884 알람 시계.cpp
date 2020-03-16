#include<iostream>

using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	if (H == 0 && M < 45) {
		cout << 23 << " " << (M + 60) - 45 << endl;
	}
	else if (H > 0 && M < 45) {
		cout << H - 1 << " " << (M + 60) - 45 << endl;
	}
	else
		cout << H << " " << M - 45 << endl;

	return 0;
}