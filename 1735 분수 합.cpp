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
	int a, b;  //ù��° �м�
	int c, d;  //�ι�° �м�
	cin >> a >> b;
	cin >> c >> d;
	int ansX, ansY; //���� �м�

	ansY = lcm(b, d);
	ansX = a * (ansY / b) + c * (ansY / d);

	int g = gcd(ansX, ansY);
	ansX /= g;
	ansY /= g;

	cout << ansX << " " << ansY << endl;

	return 0;
}