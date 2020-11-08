#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

void print(string &s, bool flip) {
	if (flip) {
		for (int i = s.length() - 1; i >= 0; --i) {
			cout << s[i];
		}
	}
	else
		cout << s;

	s = "";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, temp = "";
	getline(cin, s);

	bool flip = true;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '<') {
			print(temp, flip);
			cout << s[i];
			flip = false;
		}
		else if (s[i] == '>') {
			print(temp, flip);
			cout << s[i];
			flip = true;
		}
		else if (s[i] == ' ') {
			print(temp, flip); 
			cout << s[i];
		}
		else
			temp += s[i];
	}

	if (temp.length() > 0)
		print(temp, flip);

	return 0;
}