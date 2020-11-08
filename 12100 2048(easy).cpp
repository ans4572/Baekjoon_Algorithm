#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

const int SIZE = 21;
int N, ans = 0;
int board[SIZE][SIZE];
bool combine[SIZE][SIZE];

void move(int d) {
	memset(combine, false, sizeof(combine));
	//위

	if (d == 0) {
		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int n = i;
				//위로 가면서 숫자 찾기
				while (n - 1 >= 0 && board[n - 1][j] == 0) n--;

				//숫자가 같고 아직 합쳐지지 않은 블록인 경우
				if (board[i][j] == board[n - 1][j] && !combine[n - 1][j]) {
					board[n - 1][j] = board[i][j] * 2;
					combine[n - 1][j] = true;
					board[i][j] = 0;
				}
				else {
					board[n][j] = board[i][j];
					if (i != n)
						board[i][j] = 0;
				}
			}
		}
	}
	//아래
	else if (d == 1) {
		for (int i = N - 2; i >= 0; --i) {
			for (int j = 0; j < N; ++j) {
				int n = i;
				//아래로 가면서 숫자 찾기
				while (n + 1 < N && board[n + 1][j] == 0) n++;

				//숫자가 같고 아직 합쳐지지 않은 블록인 경우
				if (board[i][j] == board[n + 1][j] && !combine[n + 1][j]) {
					board[n + 1][j] = board[i][j] * 2;
					combine[n + 1][j] = true;
					board[i][j] = 0;
				}
				else {
					board[n][j] = board[i][j];
					if (i != n)
						board[i][j] = 0;
				}
			}
		}
	}
	//왼쪽
	else if (d == 2) {
		for (int i = 0; i < N; ++i) {
			for (int j = 1; j < N; ++j) {
				int n = j;
				//왼쪽으로 가면서 숫자 찾기
				while (n - 1 >= 0 && board[i][n - 1] == 0) n--;

				//숫자가 같고 아직 합쳐지지 않은 블록인 경우
				if (board[i][j] == board[i][n - 1] && !combine[i][n - 1]) {
					board[i][n - 1] = board[i][j] * 2;
					combine[i][n - 1] = true;
					board[i][j] = 0;
				}
				else {
					board[i][n] = board[i][j];
					if (j != n)
						board[i][j] = 0;
				}
			}
		}

	}
	//오른쪽
	else if (d == 3) {
		for (int i = 0; i < N; ++i) {
			for (int j = N - 2; j >= 0; --j) {
				int n = j;
				//오른쪽으로 가면서 숫자 찾기
				while (n + 1 < N && board[i][n + 1] == 0) n++;

				//숫자가 같고 아직 합쳐지지 않은 블록인 경우
				if (board[i][j] == board[i][n + 1] && !combine[i][n + 1]) {
					board[i][n + 1] = board[i][j] * 2;
					combine[i][n + 1] = true;
					board[i][j] = 0;
				}
				else {
					board[i][n] = board[i][j];
					if (j != n)
						board[i][j] = 0;
				}
			}
		}
	}
	return;
}

void copy(int a[][SIZE], int b[][SIZE]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = b[i][j];
		}
	}
}

void DFS(int count) {
	if (count == 5) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (ans < board[i][j])
					ans = board[i][j];
			}
		}
	}
	else {
		int temp[SIZE][SIZE];
		copy(temp, board);

		for (int i = 0; i < 4; ++i) {
			move(i);
			DFS(count + 1);
			copy(board, temp);
		}
	}

	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}

	DFS(0);

	cout << ans << endl;

	return 0;
}