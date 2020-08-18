#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Point {
public:
	int x, y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int M, N, day = 0;
queue<Point> q;
int dx[4] = { -1,0,+1,0 };
int dy[4] = { 0,+1,0,-1 };

bool isPossible(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	else
		return false;
}

void BFS(vector<vector<int> > &map) {
	if (q.empty())
		return;
	else {
		int count = q.size();  //�ش� ��¥�� ����ؾ� �� �丶�� ����
		for (int i = 0; i < count; ++i) {
			Point p = q.front();
			int newX, newY;
			q.pop();
			for (int j = 0; j < 4; ++j) {
				newX = p.x + dx[j];
				newY = p.y + dy[j];
				if (isPossible(newX, newY) && map[newX][newY] == 0 ) {
					map[newX][newY] = 1;
					q.push(Point(newX, newY));
				}
			}
		}
		day++;
		BFS(map);
	}
}

int main() {
	cin >> M >> N;
	bool change = false;

	vector<vector<int> > map(N, vector<int>(M));
	vector<vector<int> > days(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] != map[0][0])
				change = true;
			if (map[i][j] == 1)
				q.push(Point(i, j));
			days[i][j] = 0;
		}
	}

	//��ȭ�� �߻����� ���� ���
	if (!change) {
		if (map[0][0] == 1)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}

	BFS(map);

	//BFS�� �� �������� �� ���� �丶�䰡 �ִ��� Ȯ���ϰ�
	//�� ���� �丶�䰡 �ִٸ� -1 ���
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	//�丶�䰡 �� ���� �� �ִٸ� �ɸ� ��¥ ���
	cout << day - 1 << endl;

	return 0;
}