#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N, M;
char map[1001][1001];            //0: move O, 1: move X
bool notBreakVisit[1001][1001];  //벽을 안부순 상태에서 방문 여부
bool breakVisit[1001][1001];     //벽을 부순 경우 방문 여부

int dn[4] = { 1,0,-1,0 };
int dm[4] = { 0,1,0,-1 };

class State {
public:
	int n, m, count;
	bool isBreak;

	State(int n, int m, bool isBreak, int count = 0) {
		this->n = n;
		this->m = m;
		this->isBreak = isBreak;
		this->count = count;
	}
};

bool inMap(int n, int m) {
	return n >= 1 && n <= N && m >= 1 && m <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> map[i][j];
		}
	}

	queue<State> q;
	q.push(State(1, 1, false, 0));
	notBreakVisit[1][1] = true;
	int nextN, nextM, ans = 10000001;

	while (!q.empty()) {
		State now = q.front();
		q.pop();

		if (now.n == N && now.m == M) {
			if (ans > now.count)
				ans = now.count;
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			nextN = now.n + dn[i];
			nextM = now.m + dm[i];

			if (!inMap(nextN, nextM))
				continue;

			//now가 벽을 이미 부쉈는지에 따라 나눔
			if (now.isBreak) {
				if (map[nextN][nextM] == '1')  //이미 벽을 부쉈는데 다음도 벽인 경우
					continue;
				else if (map[nextN][nextM] == '0' && !breakVisit[nextN][nextM]) {
					breakVisit[nextN][nextM] = true;
					q.push(State(nextN, nextM, true, now.count + 1));
				}
			}
			else {
				if (!notBreakVisit[nextN][nextM]) {
					if (map[nextN][nextM] == '1') {  //다음이 벽인데 아직 벽을 안부순 경우
						q.push(State(nextN, nextM, true, now.count + 1));
						breakVisit[nextN][nextM] = true;
					}
					else {
						q.push(State(nextN, nextM, false, now.count + 1));
						notBreakVisit[nextN][nextM] = true;
					}
				}
			}
		}
	}

	if (ans == 10000001)
		cout << -1 << endl;
	else
		cout << ans + 1 << endl;

	return 0;
}