#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[301][301];

int main() {
	int N, M, K;
	cin >> N >> M;

	vector<vector<int> > arr(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> arr[i][j];
			dy[i][j] = arr[i][j] + dy[i][j - 1] + dy[i - 1][j] - dy[i - 1][j - 1];
		}
	}

	cin >> K;
	int i, j, x, y;
	for (int t = 0; t < K; ++t) {
		cin >> i >> j >> x >> y;
		if (i == x && j == y) {
			cout << arr[i][j] << endl;
		}
		else if (i == 1 && i == x) {
			cout << dy[x][y] - dy[x][j - 1] << endl;
		}
		else if (j == 1 && j == y) {
			cout << dy[x][y] - dy[i - 1][y] << endl;
		}
		else {
			cout << dy[x][y] - dy[i - 1][y] - dy[x][j - 1] + dy[i - 1][j - 1] << endl;
		}
	}

	return 0;
}