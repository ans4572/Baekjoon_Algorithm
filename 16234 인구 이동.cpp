#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N, L, R;
int A[51][51];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans = 0;

bool possible(int y, int x, int nextY, int nextX) {
	if (abs(A[y][x] - A[nextY][nextX]) >= L && abs(A[y][x] - A[nextY][nextX]) <= R)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}

	while (true) {
		bool exist = false;  //연합 존재 여부
		queue<pair<int, int> > q;
		queue<pair<int, int> > vec;   //연합 저장
		bool visit[51][51] = { false };

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {

				if (visit[i][j])
					continue;

				int sum = A[i][j];
				q.push(make_pair(i, j));
				vec.push(make_pair(i, j));
				visit[i][j] = true;
				
				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k) {
						int nextY = now.first + dy[k];
						int nextX = now.second + dx[k];

						if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N
							|| visit[nextY][nextX] || !possible(now.first, now.second, nextY, nextX))
							continue;

						exist = true;
						sum += A[nextY][nextX];
						q.push(make_pair(nextY, nextX));
						vec.push(make_pair(nextY, nextX));
						visit[nextY][nextX] = true;
						
					}
				}

				int avg = sum / vec.size();
				
				//갱신
				while (!vec.empty()) {
					A[vec.front().first][vec.front().second] = avg;
					vec.pop();
				}
			}
		}

		if (!exist)
			break;

		ans++;
	}

	cout << ans << endl;

	return 0;
}