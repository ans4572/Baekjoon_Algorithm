#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int n;

	string name, kind;
	for (int test = 0; test < T; ++test) {
		map<string, int> dress;

		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> name >> kind;

			dress[kind] += 1;  //개수 증가
		}

		int ans = 1;
		for (auto it = dress.begin(); it != dress.end(); ++it) {
			ans *= (it->second + 1);
		}
		cout << ans - 1 << endl;
	}

	return 0;
}

