#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int R, C;
char map[10001][501];
bool visit[10001][501];
int ans = 0;

//대각선 위, 오른쪽, 대각선 아래순
int dr[3] = {-1,0,+1};

bool inMap(int r, int c) {
	return r >= 0 && r < R && c >= 0 && c < C;
}

bool goal = false;
void DFS(int r, int c) {
	if (c == C - 1) {
		goal = true;
		ans++;
		return;
	}
	else {
		for (int i = 0; i < 3; ++i) {
			if (!visit[r + dr[i]][c + 1] && inMap(r+dr[i],c+1) && map[r+dr[i]][c+1] == '.') {
				visit[r + dr[i]][c + 1] = true;
				DFS(r + dr[i], c + 1);
				if (goal) return;
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; ++i) {
		goal = false;
		DFS(i, 0);
	}

	cout << ans << endl;

	return 0;
}