#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int N, M;
vector<vector<int> > board;
vector<vector<bool> > visit;
int dn[4] = { 0,1,0,-1 };
int dm[4] = { 1,0,-1,0 };

bool inBoard(int n, int m) {
	return (n >= 0) && (n < N) && (m >= 0) && (m < M);
}

//DFS를 활용하여 4가지 테트로미노를 만들어서 가장 큰 값 반환
int tetromino(int n, int m, int count) {
	if (count == 4) {
		return 0;
	}

	int result = 0;
	for (int i = 0; i < 4; ++i) {
		int nn = n + dn[i];
		int mm = m + dm[i];

		if (inBoard(nn, mm) && !visit[nn][mm]) {
			visit[nn][mm] = true;
			result = max(result, board[n][m] + tetromino(nn, mm, count + 1));
			visit[nn][mm] = false;
		}
	}

	return result;
}

//DFS로 불가능한 모델 ㅜ
int exceptionModel(int n, int m) {
	int result = 0;

	//ㅜ
	if (n + 1 < N && m + 2 < M)
		result = max(result, board[n][m] + board[n][m + 1] + board[n][m + 2] + board[n + 1][m + 1]);
	//ㅗ
	if (n - 1 >= 0 && m + 2 < M)
		result = max(result, board[n][m] + board[n][m + 1] + board[n][m + 2] + board[n - 1][m + 1]);
	//ㅏ
	if (n + 2 < N && m + 1 < M)
		result = max(result, board[n][m] + board[n + 1][m] + board[n + 2][m] + board[n + 1][m + 1]);
	//ㅓ
	if (n + 2 < N && m - 1 >= 0)
		result = max(result, board[n][m] + board[n + 1][m] + board[n + 2][m] + board[n + 1][m - 1]);

	return result;
}

int main() {
	cin >> N >> M;

	board.resize(N, vector<int>(M));
	visit.resize(N, vector<bool>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &board[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visit[i][j] = true;   //방문 표시
			ans = max(ans, tetromino(i, j, 0));
			ans = max(ans, exceptionModel(i, j));
			visit[i][j] = false;  //방문 표시 해제
		}
	}

	cout << ans << endl;

	return 0;
}