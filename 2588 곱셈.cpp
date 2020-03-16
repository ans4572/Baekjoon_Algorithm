#include<iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x;
	cin >> y;
	
	cout << x * (y % 10) << endl;
	cout << x * (y % 100 - y % 10) / 10 << endl;
	cout << x * (y / 100) << endl;
	cout << x * y << endl;

	return 0;
}