#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s, ans = "";
	cin >> s;


	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			ans += s[i];
	}

	cout << ans << endl;

	return 0;
}