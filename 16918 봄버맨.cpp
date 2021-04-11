#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

char map[201][201];
int bombTime[201][201];
int R, C, N;

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

bool inMap(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

void fillBomb(int t) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == 'O')
				continue;

			map[i][j] = 'O';
			bombTime[i][j] = t + 3;
		}
	}
}

void bomb(int t) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (bombTime[i][j] == t) {
				for (int k = 0; k < 4; ++k) {
					if (inMap(i + dr[k], j + dc[k])) {
						map[i + dr[k]][j + dc[k]] = '.';
					}
				}

				map[i][j] = '.';
				bombTime[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> N;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				bombTime[i][j] = 3;
			}
		}
	}

	int t = 2, nowQ = 1;
	while (t <= N) {
		if (t % 2 == 1) {
			bomb(t);
		}
		else
			fillBomb(t);

		t++;
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}