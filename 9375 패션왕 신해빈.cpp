// https://www.acmicpc.net/problem/9375

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main() {
	int T, N;
	string s1, s2;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		cin >> N;

		map<string, int> map;
		for (int i = 0; i < N; ++i) {
			cin >> s1 >> s2;
			if (map[s2]) map[s2]++;
			else map[s2] = 1;
		}

		long long ret = 1;
		for (auto n : map) {
			ret *= ((long long)n.second + 1);
		}
		cout << ret - 1 << "\n";
	}

	return 0;
}