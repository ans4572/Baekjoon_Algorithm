#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int> > graph(N + 1, vector<int>(N + 1, 100));

	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= N; ++i)
		graph[i][i] = 0;

	//플로이드 와샬 알고리즘 활용
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int min_score = 100, score;
	vector<int> candidate;
	for (int i = 1; i <= N; ++i) {
		score = 0;
		for (int j = 1; j <= N; ++j) {
			if (score < graph[i][j])
				score = graph[i][j];
		}
		if (min_score > score) {
			min_score = score;
			candidate.clear();
			candidate.push_back(i);
		}
		else if (min_score == score) {
			candidate.push_back(i);
		}
	}

	cout << min_score << " " << candidate.size() << endl;
	for (int i = 0; i < candidate.size(); i++) {
		cout << candidate[i] << " ";
	}

	return 0;
}