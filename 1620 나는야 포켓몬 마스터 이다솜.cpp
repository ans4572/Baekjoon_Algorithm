// https://www.acmicpc.net/problem/1620

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> _map;
	map<int, string> _map2;

	vector<string> arr;
	string s;
	arr.push_back("");
	for (int i = 0; i < N; ++i) {
		cin >> s;
		_map[s] = i + 1;
		_map2[i + 1] = s;
	}

	for (int i = 0; i < M; ++i) {
		cin >> s;

		// 문자인 경우
		if (atoi(s.c_str()) == 0)
			cout << _map[s] << "\n";
		// 숫자인 경우
		else
			cout << _map2[atoi(s.c_str())] << "\n";
	}

	return 0;
}