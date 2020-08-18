#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int min(string a, string b) {
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == '6')
			a[i] = '5';
	}

	for (int i = 0; i < b.length(); ++i) {
		if (b[i] == '6')
			b[i] = '5';
	}

	return stoi(a) + stoi(b);
}

int max(string a, string b) {
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == '5')
			a[i] = '6';
	}

	for (int i = 0; i < b.length(); ++i) {
		if (b[i] == '5')
			b[i] = '6';
	}

	return stoi(a) + stoi(b);
}

int main() {
	string a, b;
	cin >> a >> b;

	cout << min(a, b) << " " << max(a,b) << endl;

	return 0;
}