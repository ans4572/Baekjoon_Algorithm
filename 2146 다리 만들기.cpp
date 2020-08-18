#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int N;
int map[100][100];
bool visit[100][100];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 100 * 100;
queue<pair<int, int> > q;

//���� �� ���� ���� Ȯ�� �Լ�
bool possible(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	else
		return false;
}

//Q�ʱ�ȭ �Լ�
void qInit() {
	while (!q.empty())
		q.pop();
}

//�� ���� ���̵带 �ϳ��� BFS�� ���� ����� �ٸ������� �Ÿ� ã��
int BFS(int y, int x, int islandNum) {
	qInit();
	int tx, ty;

	memset(visit, false, sizeof(visit));
	q.push(make_pair(y, x));
	visit[y][x] = true;

	while (!q.empty()) {
		ty = q.front().first;
		tx = q.front().second;

		//���� BFS �������� ���̰� ������� ���� ª�� �ٸ��� ���̺��� �� ��� 
		//�� �̻� BFS������ �ʿ� �����Ƿ� �Լ� ����
		if (ans < (abs(tx - x) + abs(ty - y)))
			return 0;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			if (possible(tx + dx[i], ty + dy[i]) && visit[ty + dy[i]][tx+dx[i]] == false) {
				if (map[ty + dy[i]][tx + dx[i]] == 0) {
					visit[ty + dy[i]][tx + dx[i]] = true;
					q.push(make_pair(ty + dy[i], tx + dx[i]));
				}
				//�ٸ� ���� ã�� ���
				else if (map[ty + dy[i]][tx + dx[i]] != islandNum) {
					return (abs(tx + dx[i] - x) + abs(ty + dy[i] - y)) - 1;
				}
			}
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	int islandNum = 0;
	int tx, ty;
	memset(visit, false, sizeof(visit));

	//BFS�� Ȱ���Ͽ� ������ ��ȣ �ٸ��� �ο��ϱ�
	//i: y, j: x 
	for (int i = 0; i < N; ++i) {
		qInit();
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				islandNum++;
				q.push(make_pair(i, j));
				visit[i][j] = true;

				while (!q.empty()) {
					ty = q.front().first;
					tx = q.front().second;
					map[ty][tx] = islandNum;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						if (possible(tx + dx[k], ty + dy[k]) && map[ty + dy[k]][tx + dx[k]] == 1 && visit[ty + dy[k]][tx + dx[k]] == false) {
							visit[ty + dy[k]][tx + dx[k]] = true;
							q.push(make_pair(ty + dy[k], tx + dx[k]));
						}
					}
				}
			}
		}
	}

	int temp;
	//map ��ü�� ���鼭 ������ �����ڸ� �κ��� BFS�� ���� ���� ����� ������ ���� ã�� 
	//i: y, j: x
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (possible(j + dx[k], i + dy[k]) && map[i][j] != 0 && map[i + dy[k]][j + dx[k]] == 0) {
					temp = BFS(i, j, map[i][j]);
					if (ans > temp && temp > 0) ans = temp;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}