#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int> > graph(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> graph[i][j];
		}
	}

	//플로이드 와샬 알고리즘 적용
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}