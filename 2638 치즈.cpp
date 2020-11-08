#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int N, M;  //N: ����, M: ����
int map[101][101];  //0: �� ����, 1: ġ��
bool visit[101][101];
queue<pair<int, int> > q;

int dn[4] = { 1,0,-1,0 };
int dm[4] = { 0,1,0,-1 };

int inMap(int n, int m) {
	return n >= 0 && n < N && m >= 0 && m < M;
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

	int nextN, nextM, ans = 0;
	bool finish = false;

	while (1) {
		finish = true;

		memset(visit, false, sizeof(visit));

		//�ܺ� ���⸦ BFS�� Ȱ���Ͽ� ġ� 2�� �̻� ��� �� �Ǻ�
		q.push(make_pair(0, 0));
		while (!q.empty()) {

			pair<int, int> now = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				nextN = now.first + dn[i];
				nextM = now.second + dm[i];
				if (inMap(nextN, nextM) && !visit[nextN][nextM] && map[nextN][nextM] == 0) {
					visit[nextN][nextM] = true;
					q.push(make_pair(nextN, nextM));
				}
				else if (inMap(nextN, nextM) && map[nextN][nextM] >= 1) {
					map[nextN][nextM]++;
				}
			}
		}

		//ġ�� ���̱�
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (map[i][j] >= 3)
				{
					finish = false;
					map[i][j] = 0;
				}
				else if (map[i][j] == 2) map[i][j] = 1;
			}
		}

		if (finish) break;

		ans++;
	}

	cout << ans << endl;

	return 0;
}