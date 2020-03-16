#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int S(int n) {
	return pow(2,pow(2, n)) + 1;
}

int gcd(int a, int b) {
	int c;
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return b;
}

int main() {
	int A, B;
	cin >> A >> B;

	for (int i = A; i <= B; ++i) {

	}

	return 0;
}