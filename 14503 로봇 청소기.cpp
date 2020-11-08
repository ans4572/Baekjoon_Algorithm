#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
int map[51][51];  //0: 빈칸, 1: 벽, 2: 청소한 곳
int dr[4] = { -1,0,1,0 };  //세로
int dc[4] = { 0,1,0,-1 };  //가로
bool isFinish = false;

class robot {
public:
	int r, c, d;

	robot() {}
	robot(int r, int c, int d) {
		this->r = r;
		this->c = c;
		this->d = d;
	}
};

bool finish(int r, int c) {
	//4방향 중에 하나라도 빈 칸이 존재하는 경우
	for (int i = 0; i < 4; ++i) {
		if (map[r + dr[i]][c + dc[i]] == 0)
			return false;
	}

	return true;
}

int main() {
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;  //d: 0=>북쪽, 1=>동쪽, 2=>남쪽, 3=>서쪽

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	while (true) {
		map[r][c] = 2;

		if (finish(r, c))
		{
			int nextD = (d + 2) % 4;  //후진할 방향
			if (map[r + dr[nextD]][c + dc[nextD]] == 1)  //후진할 방향이 벽인 경우 끝
				break;
			//후진할 방향이 벽이 아닌 경우
			else {
				r += dr[nextD];
				c += dc[nextD];
			}
		}
		else {
			int nextR, nextC, nextD;
			nextD = (d + 3) % 4;
			nextR = r + dr[nextD];
			nextC = c + dc[nextD];

			if (map[nextR][nextC] == 0) {
				r = nextR;
				c = nextC;
				d = nextD;
			}
			else {
				d = nextD;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 2) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}