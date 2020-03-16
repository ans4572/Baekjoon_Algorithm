#include<iostream>
#include<algorithm>
#include<vector>

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

int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}

int main() {
	int a, b;  //첫번째 분수
	int c, d;  //두번째 분수
	cin >> a >> b;
	cin >> c >> d;
	int ansX, ansY; //정답 분수

	ansY = lcm(b, d);
	ansX = a * (ansY / b) + c * (ansY / d);

	int g = gcd(ansX, ansY);
	ansX /= g;
	ansY /= g;

	cout << ansX << " " << ansY << endl;

	return 0;
}