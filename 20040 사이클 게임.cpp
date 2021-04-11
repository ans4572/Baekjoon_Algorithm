#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int point[500000];

int Find(int x) {
	if (x == point[x])
		return x;
	else {
		point[x] = Find(point[x]);
		return point[x];
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	point[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		point[i] = i;
	}

	int a, b;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;

		//사이클이 연결되는 경우
		if (Find(a) == Find(b)) {
			cout << i << endl;
			return 0;
		}

		Union(a, b);
	}

	cout << 0 << endl;

	return 0;
}