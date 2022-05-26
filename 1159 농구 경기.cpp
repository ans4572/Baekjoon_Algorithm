// https://www.acmicpc.net/problem/1159

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int alphabet[26] = { 0 };

	string name;
	for (int i = 0; i < N; ++i) {
		cin >> name;
		alphabet[name[0] - 'a']++;
	}

	string ans = "";
	for (int i = 0; i < 26; ++i) {
		if (alphabet[i] >= 5)
			ans += (i + 'a');
	}

	if (ans == "") ans = "PREDAJA";

	cout << ans << endl;

	return 0;
}