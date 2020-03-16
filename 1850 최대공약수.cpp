#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int gcd(long long a, long long b) {
	long long c;
	while (a%b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	long long A, B, tmp;
	cin >> A >> B;

	tmp = gcd(A, B);

	for (long long i = 0; i < tmp; ++i)
		cout << 1;

	return 0;
}