#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[1000001];

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
	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	int command, a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &command, &a, &b);

		if (command == 0)
			Union(a, b);
		else {
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}