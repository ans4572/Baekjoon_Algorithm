#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int N, M;
char board[20][20];

int ans = 100;
int dn[4] = { -1,0,1,0 };
int dm[4] = { 0,-1,0,1 };

bool inBoard(int n, int m) {
	return n >= 0 && n < N&& m >= 0 && m < M;
}

void button(int n, int coin1N, int coin1M, int coin2N, int coin2M) {
	if (ans <= n)
		return;
	//10번보다 많이 눌려진 경우
	if (n > 10) {
		return;
	}
	//둘 다 떨어진 경우
	if (!inBoard(coin1N, coin1M) && !inBoard(coin2N, coin2M)) {
		return;
	}
	//둘 중 하나만 떨어진 경우
	else if ((inBoard(coin1N, coin1M) && !inBoard(coin2N, coin2M)) || (!inBoard(coin1N, coin1M) && inBoard(coin2N, coin2M))) {
		ans = min(ans, n);
		return;
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int nc1n = coin1N + dn[i];
			int nc1m = coin1M + dm[i];
			int nc2n = coin2N + dn[i];
			int nc2m = coin2M + dm[i];

			if (board[nc1n][nc1m] == '#') {
				nc1n = coin1N;
				nc1m = coin1M;
			}
			if (board[nc2n][nc2m] == '#') {
				nc2n = coin2N;
				nc2m = coin2M;
			}
			button(n + 1, nc1n, nc1m, nc2n, nc2m);
		}
	}

	return;
}

int main() {
	cin >> N >> M;

	int coin1N = -1, coin1M = -1, coin2N = -1, coin2M = -1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];

			if (board[i][j] == 'o') {
				if (coin1N == -1) {
					coin1N = i;
					coin1M = j;
				}
				else {
					coin2N = i;
					coin2M = j;
				}
			}
		}
	}

	button(0, coin1N, coin1M, coin2N, coin2M);

	if (ans > 10)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}