#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int board[1001][1001];  

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	char input;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> input;
			board[i][j] = input - '0';

			//맨 윗줄이나 맨 왼쪽줄에 1이 있는 경우
			if (board[i][j] == 1)
				ans = 1;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (board[i][j] == 0) 
				continue;
			
			//해당 좌표 기준 왼쪽, 왼쪽위, 위 최소값 + 1로 값을 재할당
			board[i][j] = min(board[i - 1][j], min(board[i - 1][j - 1], board[i][j - 1])) + 1;
			if (ans < board[i][j])
				ans = board[i][j];
		}
	}

	cout << ans * ans << endl;

	return 0;
}