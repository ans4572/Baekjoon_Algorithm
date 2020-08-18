#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class location {
public:
	int m, n, h;

	location() {}

	location(int h, int n, int m) {
		this->h = h;
		this->n = n;
		this->m = m;

	}
};

int M, N, H;
int board[100][100][100];
int date[100][100][100] = { 0 };    //날짜 계산을 위한 3차원 배열
bool visit[100][100][100];  //방문 표시
int dh[6] = { +1,0,0,-1,0,0 };
int dn[6] = { 0,+1,0,0,-1,0 };
int dm[6] = { 0,0,+1,0,0,-1 };

//범위 안에 있는지 확인하는 함수
bool possible(int h, int n, int m) {
	if (h >= 0 && h < H && n >= 0 && n < N && m >= 0 && m < M)
		return true;
	else
		return false;
}

int main() {
	cin >> M >> N >> H;

	queue<location> q;

	//board 할당 및 익은 토마토 q에 넣기
	for (int h = 0; h < H; ++h) {
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				cin >> board[h][n][m];
				if (board[h][n][m] == 1) {
					q.push(location(h, n, m));
					visit[h][n][m] = true;
				}
			}
		}
	}

	//BFS 활용
	int hh, nn, mm;
	while (!q.empty()) {
		hh = q.front().h;
		nn = q.front().n;
		mm = q.front().m;
		for (int i = 0; i < 6; ++i) {
			int newH = hh + dh[i];
			int newN = nn + dn[i];
			int newM = mm + dm[i];
			if (possible(newH, newN, newM) && board[newH][newN][newM] == 0 && visit[newH][newN][newM] == false) {
				visit[newH][newN][newM] = true;
				board[newH][newN][newM] = 1;
				q.push(location(newH, newN, newM));
				date[newH][newN][newM] = date[hh][nn][mm] + 1;
			}
		}
		q.pop();
	}

	int ans = 0;
	//전체 board를 보면서 안익은 토마토가 있는지 확인 및 최대 날짜 구하기
	for (int h = 0; h < H; ++h) {
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				if (board[h][n][m] == 0) {
					cout << -1 << endl;
					return 0;
				}
				if (ans < date[h][n][m])
					ans = date[h][n][m];
			}
		}
	}

	cout << ans << endl;

	return 0;
}