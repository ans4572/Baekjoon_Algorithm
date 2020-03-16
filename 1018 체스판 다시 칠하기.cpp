#include<iostream>

using namespace std;

int paint(char **b, int x, int y) {
	int case1_num = 0, case2_num = 0;
	char case1[8][8] = { {'W','B','W','B','W','B','W','B'},
						 {'B','W','B','W','B','W','B','W'},
						 {'W','B','W','B','W','B','W','B'},
						 {'B','W','B','W','B','W','B','W'},
						 {'W','B','W','B','W','B','W','B'},
						 {'B','W','B','W','B','W','B','W'},
						 {'W','B','W','B','W','B','W','B'},
						 {'B','W','B','W','B','W','B','W'} };

	char case2[8][8] = { {'B','W','B','W','B','W','B','W'},
						 {'W','B','W','B','W','B','W','B'},
						 {'B','W','B','W','B','W','B','W'},
						 {'W','B','W','B','W','B','W','B'},
						 {'B','W','B','W','B','W','B','W'},
						 {'W','B','W','B','W','B','W','B'},
						 {'B','W','B','W','B','W','B','W'},
						 {'W','B','W','B','W','B','W','B'} };

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (case1[i - x][j - y] != b[i][j]) {
				case1_num++;
			}
			if (case2[i - x][j - y] != b[i][j]) {
				case2_num++;
			}
		}
	}
	if (case1_num < case2_num) {
		return case1_num;
	}
	else
		return case2_num;
}

int main()
{
	int N, M;
	cin >> N >> M;

	char **board = new char*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int min = -1;
	int p;
	int count = 0;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			p = paint(board, i, j);
			if (i == 0 && j == 0) {
				min = p;
			}
			else if (min > p) {
				min = p;
			}
		}
	}
	cout << min << endl;

	for (int i = 0; i < N; ++i)
	{
		delete[] board[i];
	}
	delete[] board;

	return 0;
}