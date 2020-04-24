#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, ans = 0;
bool board[14][14] = { false };

bool isPossible(int y, int x) {
	for (int i = 0; i < x; ++i) {
		if (board[y][i]) return false;
	}
	int tx, ty; //temp x,temp y
	tx = x - 1, ty = y - 1;
	while (tx >= 0 && ty >= 0) {
		if(board[ty][tx]) return false;
		tx--;
		ty--;
	}
	tx = x - 1, ty = y + 1;
	while (tx >= 0 && ty < N) {
		if (board[ty][tx]) return false;
		tx--;
		ty++;
	}
	return true;
}

void DFS(int count) {
	if (count == N) {
		ans++;
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (!board[i][count] && isPossible(i,count)) {
				board[i][count] = true;
				DFS(count + 1);
				board[i][count] = false;
			}
		}
	}
	return;
}

int main() {
	cin >> N;

	DFS(0);

	cout << ans << endl;

	return 0;
}