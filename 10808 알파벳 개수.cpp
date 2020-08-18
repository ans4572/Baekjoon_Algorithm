#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> alphabet(26, 0);

	for (int i = 0; i < s.length(); ++i) {
		alphabet[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; ++i) {
		cout<<alphabet[i]<<" ";
	}
	cout << endl;

	return 0;
}