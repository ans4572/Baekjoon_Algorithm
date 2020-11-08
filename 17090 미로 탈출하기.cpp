#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

int N, M;
char map[501][501];
int visit[501][501];   //0: 아직 안간 곳, 1: 임시 방문 표시, 2: 탈출 가능한 곳, -1: 탈출 불가능 한 곳

bool outMap(int n, int m) {
	return n < 0 || n >= N || m < 0 || m >= M;
}

int DFS(int n, int m) {
	if (outMap(n, m) || visit[n][m] == 2) {
		return 2;
	}
	else if (visit[n][m] == -1 || visit[n][m] == 1) {
		return -1;
	}
	else {
		visit[n][m] = 1;     //임시 방문 표시
		if (map[n][m] == 'U') 
			return visit[n][m] = DFS(n - 1, m);
		else if (map[n][m] == 'R')
			return visit[n][m] = DFS(n, m + 1);
		else if (map[n][m] == 'D')
			return visit[n][m] = DFS(n + 1, m);
		else
			return visit[n][m] = DFS(n, m - 1);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visit[i][j] == 0) {
				DFS(i, j);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visit[i][j] == 2) {
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}