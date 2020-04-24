#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N, ans = 0;
long long board[101][101];
long long dy[101][101];

int main() {
	int x = 1, y = 1;

	cin >> N;

	memset(board, -1, sizeof(board));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}

	dy[1 + board[1][1]][1] = 1;
	dy[1][1 + board[1][1]] = 1;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == N && j == N)
				break;
			if (dy[i][j] != 0) {
				long long t = board[i][j];
				if (board[i + t][j] != -1)
					dy[i + t][j] += dy[i][j];
				if (board[i][j + t] != -1)
					dy[i][j + t] += dy[i][j];
			}
		}
	}

	cout << dy[N][N] << endl;

	return 0;
}