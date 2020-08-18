#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s, pattern;

bool search(int index) {
	for (int i = 1; i < pattern.size(); ++i) {
		if (s[index + i] != pattern[i]) 
			return false;
	}

	return true;
}

int main() {
	getline(cin, s, '\n');
	getline(cin, pattern, '\n');

	if (s.size() < pattern.size()) {
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i <= s.size() - pattern.size(); ++i) {
		if (s[i] == pattern[0]) {
			if (search(i)) {
				i += (pattern.size() - 1);
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}