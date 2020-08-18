#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s, del = "CAMBRIDGE";
	cin >> s;

	bool remove = false;
	for (int i = 0; i < s.length(); ++i) {
		remove = false;
		for (int j = 0; j < del.length(); ++j) {
			if (s[i] == del[j]) {
				remove = true;
				break;
			}
		}
		if (!remove)
			cout << s[i];
	}

	return 0;
}