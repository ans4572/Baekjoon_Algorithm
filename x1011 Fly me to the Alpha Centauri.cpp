#include<iostream>

using namespace std;

int main() {
	long long T;
	long long x, y;
	long long k; //move value
	long long m; //mid
	long long time;
	cin >> T;
	for (int i = 0; i < T; i++) {
		k = 1;
		time = 0;
		cin >> x >> y;

		m = (x + y) / 2;
		if ((y-x) % 2 == 1)
			m++;

	}

	return 0;
}