#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> S;
	map<string, int>::iterator iter;

	string input;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		S.insert(make_pair(input, 0));
	}

	for (int i = 0; i < M; ++i) {
		cin >> input;
		
		iter = S.find(input);
		if(iter != S.end())
			S.find(input)->second++;
	}

	int ans = 0;
	for (iter = S.begin(); iter != S.end(); ++iter) {
		ans += iter->second;
	}

	cout << ans << endl;

	return 0;
}