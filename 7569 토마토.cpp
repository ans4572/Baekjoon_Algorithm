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
int date[100][100][100] = { 0 };    //��¥ ����� ���� 3���� �迭
bool visit[100][100][100];  //�湮 ǥ��
int dh[6] = { +1,0,0,-1,0,0 };
int dn[6] = { 0,+1,0,0,-1,0 };
int dm[6] = { 0,0,+1,0,0,-1 };

//���� �ȿ� �ִ��� Ȯ���ϴ� �Լ�
bool possible(int h, int n, int m) {
	if (h >= 0 && h < H && n >= 0 && n < N && m >= 0 && m < M)
		return true;
	else
		return false;
}

int main() {
	cin >> M >> N >> H;

	queue<location> q;

	//board �Ҵ� �� ���� �丶�� q�� �ֱ�
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

	//BFS Ȱ��
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
	//��ü board�� ���鼭 ������ �丶�䰡 �ִ��� Ȯ�� �� �ִ� ��¥ ���ϱ�
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