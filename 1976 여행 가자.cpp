#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[201];

int Find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (x > y) parent[x] = y;
		else parent[y] = x;
	}
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	vector<int> arr(m);
	vector<vector<int> > graph(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1)
				Union(i, j);
		}
	}

	int p;
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		if (i == 0)
			p = parent[arr[0]];

		if (p != parent[arr[i]]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}