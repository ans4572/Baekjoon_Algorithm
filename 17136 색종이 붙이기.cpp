#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int board[10][10];
int paperCount[6];       //갹 종류 색종이 카운트 
int ans = 100;

//가능한 색종이 판별
bool possible(int x, int y, int n) {
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (i >= 10 || j >= 10 || board[i][j] == 0)
				return false;
		}
	}

	return true;
}

void cover(int y, int x) {
	if (x == 10) {
		cover(y + 1, 0);
		return;
	}

	//마지막 확인
	if (y == 10) {
		int sum = 0;
		for (int i = 1; i <= 5; ++i) {
			sum += paperCount[i];
		}

		ans = min(ans, sum);
		return;
	}

	if (board[y][x] == 0) {
		cover(y, x + 1);
		return;
	}

	//1인 경우 색종이 하나씩 확인
	for (int n = 5; n >= 1; --n) {
		if (possible(x, y, n) && paperCount[n] < 5) {
			//색종이 덮기
			for (int i = y; i < y + n; ++i) {
				for (int j = x; j < x + n; ++j) {
					board[i][j] = 0;
				}
			}

			paperCount[n]++;

			cover(y, x + 1);  //다음 칸 이동

			//색종이 치우기
			for (int i = y; i < y + n; ++i) {
				for (int j = x; j < x + n; ++j) {
					board[i][j] = 1;
				}
			}

			paperCount[n]--;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> board[i][j];
		}
	}

	cover(0, 0);

	if (ans == 100)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}