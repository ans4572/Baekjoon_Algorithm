#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C, ans = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
char board[20][20];
bool alphabet[26];

//board범위 내에 있는지 확인
bool possible(int x, int y) {
	if (y >= 0 && y < R && x >= 0 && x < C)
		return true;
	else
		return false;
}

//백트래킹을 활용한 DFS
void DFS(int x, int y, int count) {
	int nextX, nextY;

	for (int i = 0; i < 4; ++i) {
		nextX = x + dx[i];
		nextY = y + dy[i];
		if (possible(nextX, nextY) && alphabet[board[nextY][nextX] - 'A'] == false) {
			alphabet[board[nextY][nextX] - 'A'] = true;
			DFS(nextX, nextY, count + 1);
			alphabet[board[nextY][nextX] - 'A'] = false;
		}
	}

	if (ans < count)
		ans = count;
}

int main() {
	cin >> R >> C;

	vector<char> visit;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
		}
	}

	alphabet[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);

	cout << ans << endl;

	return 0;
}