#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
void DFS(int count, int n, vector<int> seq) {
	seq[count] = n;
	if (count == M) {
		for (int i = 1; i <= M; ++i) {
			printf("%d ", seq[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1; i <= N; ++i) {
			DFS(count + 1, i, seq);
		}
	}
}

int main() {
	cin >> N >> M;

	vector<int> seq(N + 1);
	for (int i = 1; i <= N; ++i) {
		DFS(1, i, seq);
	}

	return 0;
}