#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M; //N: 도시(node) 개수, M: 버스(edge) 개수
	cin >> N >> M;

	vector<vector<int> > map(N + 1, vector<int>(N + 1, 10000001));

	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		if (map[a][b] != 0 && map[a][b] > c)
			map[a][b] = c;
	}

	for (int i = 1; i <= N; ++i) {
		map[i][i] = 0;
	}

	//플로이드 와샬 알고리즘 적용
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (map[i][j] == 10000001)
				map[i][j] = 0;
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}