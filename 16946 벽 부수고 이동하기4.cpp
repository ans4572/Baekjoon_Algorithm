#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
char map[1001][1001];
int group[1001][1001];
int groupCount[10000000];
int groupIndex = 1;

int dn[4] = { 0,-1,0,1 };
int dm[4] = { 1,0,-1,0 };

bool inMap(int n, int m) {
	return n >= 0 && n < N&& m >= 0 && m < M;
}

void bfs(int n, int m) {
	queue<pair<int, int> > q;
	group[n][m] = groupIndex;
	q.push(make_pair(n, m));

	int nextN, nextM;
	int count = 1;

	//그룹화 진행
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			nextN = now.first + dn[i];
			nextM = now.second + dm[i];

			if (inMap(nextN, nextM) && map[nextN][nextM] == '0' && group[nextN][nextM] == 0) {
				q.push(make_pair(nextN, nextM));
				group[nextN][nextM] = groupIndex;
				count++;
			}
		}
	}

	//개수 카운트 및 인덱스 증가
	groupCount[groupIndex] = count;
	groupIndex++;

	return;
}

//매개변수 좌표 벽을 부수고 이동할 수 있는 칸 개수 계산
int breakCount(int n, int m) {
	int count = 0;
	vector<bool> groupVisit(groupIndex, false);

	for (int i = 0; i < 4; ++i) {
		int nextN = n + dn[i];
		int nextM = m + dm[i];
		if (inMap(nextN, nextM) && map[nextN][nextM] == '0') {
			if (!groupVisit[group[nextN][nextM]]) {
				groupVisit[group[nextN][nextM]] = true;
				count += groupCount[group[nextN][nextM]];
			}
		}
	}

	return count;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '1')
				group[i][j] = -1;
		}
	}

	//bfs로 빈 칸 그룹화 진행
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == '0' && group[i][j] == 0) {
				bfs(i, j);
			}
		}
	}

	//결과 출력
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == '1') {
				cout << (breakCount(i, j) + 1) % 10;
			}
			else
				cout << 0;
		}
		cout << "\n";
	}

	return 0;
}