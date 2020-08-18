#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<int> > map(N + 1, vector<int>(N + 1,100000));

	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}

	for (int i = 1; i <= N; ++i)
		map[i][i] = 0;

	//플로이드 와샬 알고리즘 활용
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (ans < map[i][X] + map[X][i])
			ans = map[i][X] + map[X][i];
	}

	cout << ans << endl;

	return 0;
}