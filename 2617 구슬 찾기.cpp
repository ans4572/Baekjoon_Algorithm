#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int N, M;
vector<vector<int> > graph;  // graph[a][b] : a와 b의 관계
							 // 0 = ? , -1: a는 b보다 작다, 1: a는 b보다 크다.

void update(int n) {
	for (int i = 1; i <= N; ++i) {
		if (graph[n][i] == -1) {
			for (int j = 1; j <= N; ++j) {
				if (graph[i][j] == -1) {
					graph[n][j] = -1;
					graph[j][n] = 1;
				}
			}
		}
		else if (graph[n][i] == 1) {
			for (int j = 1; j <= N; ++j) {
				if (graph[i][j] == 1) {
					graph[n][j] = 1;
					graph[j][n] = -1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	graph.resize(N + 1, vector<int>(N + 1, 0));

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = -1;
	}

	for (int i = 1; i <= N; ++i) {
		update(i);
	}

	int mid = (N + 1) / 2;
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int sC = 0, bC = 0; //small count, big count

		for (int j = 1; j <= N; ++j) {
			if (graph[i][j] == -1) sC++;
			else if (graph[i][j] == 1) bC++;
		}

		if (sC >= mid || bC >= mid) 
			ans++;
	}

	cout << ans << endl;

	return 0;
}