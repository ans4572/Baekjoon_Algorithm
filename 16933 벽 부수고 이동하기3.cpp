#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int N, M, K;
char map[1001][1001];
bool visit[1001][1001][11];

int dn[4] = { 0,-1,0,1};
int dm[4] = { 1,0,-1,0};

class state {
public:
	int n, m, k, count;  //k: �� �μ� ����, count: �Ÿ� ī��Ʈ
	bool day;            //true: ��, false: ��

	state() {}
	state(int n, int m, int k, int count, bool day) {
		this->n = n;
		this->m = m;
		this->k = k;
		this->count = count;
		this->day = day;
	}
};

bool inMap(int n, int m) {
	return n > 0 && n <= N && m > 0 && m <= M;
}

int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> map[i][j];
		}
	}

	queue<state> q;
	q.push(state(1, 1, 0, 1, true));
	visit[1][1][0] = true;

	int ans = -1;
	int nextN, nextM;

	while (!q.empty()) {
		state now = q.front();
		q.pop();

		if (now.n == N && now.m == M) {
			ans = now.count;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			nextN = now.n + dn[i];
			nextM = now.m + dm[i];

			if (!inMap(nextN, nextM))
				continue;

			// ������ �̵��� �� �ִ� �����̶�� �̵� ����
			if (map[nextN][nextM] == '0') {
				if (!visit[nextN][nextM][now.k]) {
					visit[nextN][nextM][now.k] = true;
					q.push(state(nextN, nextM, now.k, now.count + 1, !now.day));
				}
			}
			// ������ ���� ���, ���ݱ��� �μ� ���� ������ K���� �����鼭 ���� ��츸 �̵� ����
			else {
				if (now.day && now.k < K && !visit[nextN][nextM][now.k + 1]) {
					visit[nextN][nextM][now.k + 1] = true;
					q.push(state(nextN, nextM, now.k + 1, now.count + 1, !now.day));
				}
			}
		}

		//�̵� ���� ���
		q.push(state(nextN, nextM, now.k, now.count + 1, !now.day));
		continue;
	}

	cout << ans << endl;

	return 0;
}