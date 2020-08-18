#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s, change = "";
	cin >> s;

	for (int i = 0; i < s.length(); ++i) {
		change += s[s.length() - i - 1];
	}

	if (s == change)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}