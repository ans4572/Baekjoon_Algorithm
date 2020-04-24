#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
void DFS(int count, int n, vector<int> seq, vector<bool> visit) {
	visit[n] = true;
	seq[count] = n;
	if (count == M) {
		for (int i = 1; i <= M; ++i) {
			printf("%d ", seq[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1; i <= N; ++i) {
			if (visit[i] == false && seq[count] < i) {
				DFS(count + 1, i, seq, visit);
			}
		}
	}
}

int main() {
	cin >> N >> M;

	vector<int> seq(N + 1);
	vector<bool> visit(N + 1);
	for (int i = 1; i <= N; ++i) {
		DFS(1, i, seq, visit);
	}

	return 0;
}