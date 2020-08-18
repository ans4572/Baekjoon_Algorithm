#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int H, W;
int map[500][500];
int dy[500][500] = { 0 };   //dy[h][w]: (0,0)���� (h,w)���� �� �� �ִ� ����� ��
int goY[4] = { -1,0,1,0 };
int goX[4] = { 0,1,0,-1 };

int DFS(int y, int x) {
	if (y == 0 && x == 0)  //(0,0)������ �����ϸ� 1��ȯ
		return 1;

	if (dy[y][x] != 0)
		return dy[y][x];

	if (dy[y][x] == -1)
		return 0;

	//4 ������ Ž��
	for (int i = 0; i < 4; ++i) {
		int ny = y + goY[i];
		int nx = x + goX[i];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			continue;
		if (map[y][x] >= map[ny][nx])
			continue;

		int t = DFS(ny, nx);

		if (t > 0)
			dy[y][x] += t;
	}

	if (dy[y][x] == 0)  //(0,0)�� �������� ���� ���� -1�� ó��
		dy[y][x] = -1;

	return dy[y][x];
}

int main() {
	cin >> H >> W;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	dy[0][0] = 1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			DFS(i, j);
		}
	}

	if (dy[H - 1][W - 1] < 0)  //���� �� �� ���ٸ�
		cout << 0 << endl;
	else
		cout << dy[H - 1][W - 1] << endl;

	return 0;
}