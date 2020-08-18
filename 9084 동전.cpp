#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T, N, money;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N;
		int dy[10001] = { 0 };
		vector<int> coin(N);
		for (int i = 0; i < N; ++i) 
			cin >> coin[i];
		cin >> money;

		for (int i = 1; i <= money; ++i) {
			if (i % coin[0] == 0)
				dy[i] = 1;
		}

		dy[0] = 1;

		for (int i = 1; i < N; ++i) {
			for (int j = coin[i]; j <= money; ++j) {
				dy[j] = dy[j] + dy[j - coin[i]];
			}
		}

		cout << dy[money] << endl;
	}

	return 0;
}