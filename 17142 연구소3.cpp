#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

class point {
public:
	int x, y;

	point() {}
	point(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

int N, M, ans = 1000000;
int board[51][51];
int time[51][51];     //���̷����� ������ �ð� ����
vector<point> virus;  //���̷��� ��ġ
vector<int> pick;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

bool inBoard(int y, int x) {
	return (y >= 0) && (y < N) && (x >= 0) && (x < N);
}

//Ȱ��ȭ�� ���̷��� ��ġ�� ���� �� BFS�� Ȱ���Ͽ� ���̷��� ��Ʈ����
void BFS() {
	memset(time, -1, sizeof(time));

	queue<point> q;
	for (int i = 0; i < M; ++i) {
		time[virus[pick[i]].x][virus[pick[i]].y] = 0;
		q.push(point(virus[pick[i]].x, virus[pick[i]].y));
	}

	while (!q.empty()) {
		point now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextY = now.y + dy[i];
			int nextX = now.x + dx[i];

			if (inBoard(nextY, nextX) && time[nextY][nextX] == -1 && board[nextY][nextX] != 1) {
				time[nextY][nextX] = time[now.y][now.x] + 1;
				q.push(point(nextY, nextX));
			}
		}
	}

	int maxT = 0;  //��ĭ�� ���� �ִ� �ð�
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (time[i][j] > 0 && board[i][j] == 0 && maxT < time[i][j]) {
				maxT = time[i][j];
			}
			//���� ���̷����� ������ ���� ���������� �� ������ ���� �ƴ� ��� ����
			if (time[i][j] == -1 && board[i][j] != 1)
				return;
		}
	}

	if (ans > maxT) ans = maxT;

	return;
}

//���̷��� ���� ��ġ �������� M�� �̱�
void comb(int index, int count) {
	if (count == M) {
		BFS();
	}
	else {
		for (int i = index; i < virus.size(); ++i) {
			pick[count] = i;
			comb(i + 1, count + 1);
		}
	}

	return;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &board[i][j]);

			//���̷����� ���� �� �ִ� ��ġ ����
			if (board[i][j] == 2)
				virus.push_back(point(j, i));
		}
	}

	pick.resize(virus.size());
	comb(0, 0);

	if (ans == 1000000) printf("-1\n");
	else printf("%d\n",ans);

	return 0;
}