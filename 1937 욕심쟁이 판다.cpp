#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int board[501][501];
int dy[501][501] = { 0 };   //dy[y][x]: (y,x)부터 살 수 있는 최대 일수
int goX[4] = { -1,0,1,0 };
int goY[4] = { 0,1,0,-1 };

int DFS(int y,int x) {
	if (dy[y][x] != 0)  //이미 dy가 정해져 있는 경우 
		return dy[y][x];

	dy[y][x] = 1;

	//4 방향을 탐색
	for (int i = 0; i < 4; ++i) {
		int ny = y + goY[i];
		int nx = x + goX[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (board[y][x] >= board[ny][nx])
			continue;

		dy[y][x] = max(dy[y][x], DFS(ny, nx) + 1);
	}

	return dy[y][x];
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &board[i][j]);
		}
	}

	//반복문을 돌면서 최대값 찾기
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans = max(ans, DFS(i, j));
		}
	}

	cout << ans << endl;

	return 0;
}