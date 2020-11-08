#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

vector<int> connect[100001];
int parent[100001];
bool visit[100001];

void DFS(int n) {
	visit[n] = true;

	for (int i = 0; i < connect[n].size(); ++i) {
		int next = connect[n][i];

		if (!visit[next]) {
			parent[next] = n;
			DFS(next);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;

		connect[a].push_back(b);
		connect[b].push_back(a);
	}

	DFS(1);

	for (int i = 2; i <= N; ++i)
		cout << parent[i] << "\n";

	return 0;
}