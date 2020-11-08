#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

int N, M;
int map[1001][1001];
bool visit[1001][1001][2];  //visit[x][y][m]: x,y 좌표에서 마법(m)을 쓰고 방문했는지 아닌지 저장 
int dn[4] = { 1,0,-1,0 };
int dm[4] = { 0,1,0,-1 };

class state {
public:
	int n, m, count;
	bool magic;   //마법 사용 여부

	state() {}
	state(int n, int m, bool magic, int count) {
		this->n = n;
		this->m = m;
		this->magic = magic;
		this->count = count;
	}
};

bool inMap(int n, int m) {
	return n > 0 && n <= N && m > 0 && m <= M;
}

int main() {
	cin >> N >> M;

	int Hx, Hy, Ex, Ey;
	cin >> Hx >> Hy;
	cin >> Ex >> Ey;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> map[i][j];
		}
	}

	queue<state> q;
	q.push(state(Hx, Hy, false, 0));

	int nextN, nextM, ans = -1;
	while (!q.empty()) {
		state now = q.front();
		q.pop();

		if (now.n == Ex && now.m == Ey) {
			ans = now.count;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			nextN = now.n + dn[i];
			nextM = now.m + dm[i];

			if (inMap(nextN, nextM) && !visit[nextN][nextM][now.magic]) {
				if (map[nextN][nextM] == 0) {   //벽이 아닌경우
					visit[nextN][nextM][now.magic] = true;
					q.push(state(nextN, nextM, now.magic, now.count + 1));
				}
				else if(map[nextN][nextM] == 1 && !now.magic) {  //벽이지만 아직 지팡이를 사용하지 않은 경우
					visit[nextN][nextM][true] = true;
					q.push(state(nextN, nextM, true, now.count + 1));
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}