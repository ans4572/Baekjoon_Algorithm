#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int M, N;
int arr[251][251];
bool visit[251][251];

int dm[8] = { -1,-1,0,+1,+1,+1,0,-1 };
int dn[8] = { 0,+1,+1,+1,0,-1,-1,-1 };

bool inArr(int m, int n) {
	return m >= 0 && m < M&& n >= 0 && n < N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	queue<pair<int, int> > q;
	int nextM, nextN, ans = 0;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visit[i][j] && arr[i][j] == 1) {
				q.push(make_pair(i, j));

				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					for (int t = 0; t < 8; ++t) {
						nextM = now.first + dm[t];
						nextN = now.second + dn[t];

						if (inArr(nextM, nextN) && arr[nextM][nextN] == 1 && !visit[nextM][nextN]) {
							visit[nextM][nextN] = true;
							q.push(make_pair(nextM, nextN));
						}
					}
				}

				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}