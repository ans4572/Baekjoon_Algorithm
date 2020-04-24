#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
vector<int> coin(10);

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> coin[i];
	}

	int t, ans = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (K >= coin[i]) {
			t = K / coin[i];
			K = K - t * coin[i];
			ans += t;
		}
	}

	cout << ans << endl;

	return 0;
}