#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); ++i) {
		int t = (s[i] - 'A' - 3);
		if (t < 0)
			t += 26;
		cout << (char)(t+'A');
	}

	return 0;
}