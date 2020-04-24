#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	int sum = a + b + c + d;
	cout << sum / 60 << endl;
	cout << sum % 60 << endl;

	return 0;
}