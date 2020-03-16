#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (a%b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << x + y - gcd(x, y) << endl;

	return 0;
}