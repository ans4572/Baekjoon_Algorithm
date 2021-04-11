#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int board[10][10];
bool plant[10][10];
int ans = INT_MAX;

int dx[5] = { +1, 0, -1, 0, 0};
int dy[5] = { 0, +1, 0, -1, 0};

bool possible(int x, int y) {
	for (int i = 0; i < 5; ++i) {
		if (plant[y + dy[i]][x + dx[i]])
			return false;
	}

	return true;
}

void DFS(int count, int sum) {
	if (count == 3) {
		ans = min(ans, sum);

		return;
	}

	for (int y = 1; y < N - 1; ++y) {
		for (int x = 1; x < N - 1; ++x) {
			if (possible(x, y)) {
				for (int t = 0; t < 5; ++t) {
					plant[y + dy[t]][x + dx[t]] = true;
					sum += board[y + dy[t]][x + dx[t]];
				}

				DFS(count + 1, sum);

				for (int t = 0; t < 5; ++t) {
					plant[y + dy[t]][x + dx[t]] = false;
					sum -= board[y + dy[t]][x + dx[t]];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}

	DFS(0, 0);

	cout << ans << endl;

	return 0;
}