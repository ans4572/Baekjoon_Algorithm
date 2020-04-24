#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[2][100001];

int main() {
	ios_base::sync_with_stdio(false);
	int T, N;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N;
		vector<vector<int> > arr(2, vector<int>(N+1,0));

		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> arr[i][j];
			}
		}

		dy[0][1] = arr[0][1];
		dy[1][1] = arr[1][1];

		int ans = 0;
		for (int i = 2; i <= N; ++i) {
			dy[0][i] = max(dy[1][i - 2], dy[1][i - 1]) + arr[0][i];
			dy[1][i] = max(dy[0][i - 2], dy[0][i - 1]) + arr[1][i];

			if (ans < dy[0][i])
				ans = dy[0][i];
			if (ans < dy[1][i])
				ans = dy[1][i];
		}

		cout << ans << endl;
	}

	return 0;
}