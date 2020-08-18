#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int board[501][501];
int dy[501][501] = { 0 };   //dy[y][x]: (y,x)���� �� �� �ִ� �ִ� �ϼ�
int goX[4] = { -1,0,1,0 };
int goY[4] = { 0,1,0,-1 };

int DFS(int y,int x) {
	if (dy[y][x] != 0)  //�̹� dy�� ������ �ִ� ��� 
		return dy[y][x];

	dy[y][x] = 1;

	//4 ������ Ž��
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

	//�ݺ����� ���鼭 �ִ밪 ã��
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans = max(ans, DFS(i, j));
		}
	}

	cout << ans << endl;

	return 0;
}