#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

int R, C;
char map[51][51];
bool visit[51][51];
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

class state {
public:
	int r, c, time;

	state() {}
	state(int r, int c, int time) {
		this->r = r;
		this->c = c;
		this->time = time;
	}
};

bool inMap(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

//매초 물이 차도록 하는 함수
void waterFull() {
	vector<pair<int, int> > water;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == '*') {
				water.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < water.size(); ++i) {
		for (int j = 0; j < 4; ++j) {
			int nextR = water[i].first + dr[j];
			int nextC = water[i].second + dc[j];

			if (inMap(nextR, nextC) && map[nextR][nextC] == '.') {
				map[nextR][nextC] = '*';
			}
		}
	}
}

int main() {
	cin >> R >> C;

	queue<state> q;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push(state(i,j,0));
				visit[i][j] = true;
				map[i][j] = '.';
			}
		}
	}

	int time = -1;
	while (!q.empty()) {
		state now = q.front();
		q.pop();

		//만약 고슴도치의 시간이 time보다 크다면 물들이 차도록 하기
		if (now.time > time) {
			waterFull();
			time++;
		}

		for (int i = 0; i < 4; ++i) {
			int nextR = now.r + dr[i];
			int nextC = now.c + dc[i];

			if (inMap(nextR, nextC) && !visit[nextR][nextC]) {
				if (map[nextR][nextC] == '.') {
					visit[nextR][nextC] = true;
					q.push(state(nextR, nextC, now.time + 1));
				}
				else if (map[nextR][nextC] == 'D') {
					cout << now.time + 1 << endl;
					return 0;
				}
			}
		}
	}

	cout << "KAKTUS" << endl;

	return 0;
}