#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int N, M;
char map[51][51];            //L: À°Áö, W:¹Ù´Ù
bool visit[51][51];
int ans = 0;

int dn[4] = { 1,0,-1,0 };
int dm[4] = { 0,1,0,-1 };

class Location {
public:
	int n, m, count;

	Location(int n, int m, int count) {
		this->n = n;
		this->m = m;
		this->count = count;
	}
};

bool inMap(int n, int m) {
	return n >= 0 && n < N && m >= 0 && m < M;
}

void BFS(int n, int m) {
	memset(visit, false, sizeof(visit));

	queue<Location> q;
	q.push(Location(n, m, 0));
	visit[n][m] = true;
	int nextN, nextM;

	while (!q.empty()) {
		Location now = q.front();
		q.pop();

		if (ans < now.count)
			ans = now.count;

		for (int i = 0; i < 4; ++i) {
			nextN = now.n + dn[i];
			nextM = now.m + dm[i];

			if (inMap(nextN, nextM) && !visit[nextN][nextM] && map[nextN][nextM] == 'L') {
				q.push(Location(nextN, nextM, now.count + 1));
				visit[nextN][nextM] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 'L') {
				BFS(i, j);
			}
		}
	}

	cout << ans << endl;

	return 0;
}