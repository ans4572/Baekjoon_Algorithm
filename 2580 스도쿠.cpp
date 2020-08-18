#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int board[9][9];
vector<pair<int, int> > blank;  //ä���� �ϴ� ��ǥ�� ����, first: y, second: x
bool finish = false;

void fillRow(int y, bool *num) {
	for (int i = 0; i < 9; ++i) {
		if (board[y][i] != 0)
			num[board[y][i]] = true;
	}

	return;
}

void fillCol(int x, bool* num) {
	for (int i = 0; i < 9; ++i) {
		if (board[i][x] != 0)
			num[board[i][x]] = true;
	}

	return;
}

void fillSqu(int y, int x, bool* num) {
	int nY = (y / 3) * 3;
	int nX = (x / 3) * 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[nY + i][nX + j] != 0)
				num[board[nY + i][nX + j]] = true;
		}
	}

	return;
}

bool complete() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] == 0)
				return false;
		}
	}

	return true;
}

void sudoku(int index) {
	if (finish) return;

	if (index == blank.size()) {
		if (complete()) {
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
			finish = true;
		}

		return;
	}

	bool num[10];
	memset(num, false, sizeof(num));

	//3���� ���� Ȯ�� �� �� ���� ã��
	fillRow(blank[index].first, num);
	fillCol(blank[index].second, num);
	fillSqu(blank[index].first, blank[index].second, num);

	//�� ���ڸ� Ȱ���Ͽ� ��Ʈ��ŷ
	for (int i = 1; i <= 9; ++i) {
		if (num[i] == false) {
			board[blank[index].first][blank[index].second] = i;
			sudoku(index + 1);
			board[blank[index].first][blank[index].second] = 0;
		}
	}

	return;
}

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				blank.push_back(make_pair(i, j));
		}
	}

	sudoku(0);

	return 0;
}