#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return b;
}

int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}

int main() {
	int T;
	cin >> T;

	int a, b;
	for (int i = 0; i < T; ++i) {
		cin >> a >> b;
		cout << lcm(a, b) << " " << gcd(a, b) << endl;
	}

	return 0;
}