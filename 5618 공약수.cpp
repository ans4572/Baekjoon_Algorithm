#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int a, b, c;

	if (N == 2) {
		cin >> a >> b;
		for (int i = 1; i <= min(a, b); ++i) {
			if ((a % i == 0) && (b % i == 0)) {
				cout << i << endl;
			}
		}
	}
	else if (N == 3) {
		cin >> a >> b >> c;
		for (int i = 1; i <= min(min(a, b), c); ++i) {
			if ((a % i == 0) && (b % i == 0) && (c % i == 0)) {
				cout << i << endl;
			}
		}
	}

	return 0;
}