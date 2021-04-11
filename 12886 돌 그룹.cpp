#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

bool visit[1001][1001];

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int sum = A + B + C;

	if (sum % 3) {
		cout << 0 << endl;
		return 0;
	}

	queue<pair<int,int> > q;
	q.push(make_pair(A,B));
	visit[A][B] = true;

	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		int z = sum - x - y;

		if (x == y && y == z) {
			cout << 1 << endl;
			return 0;
		}

		int nx[] = { x, x, y }, ny[] = { y, z, z };
		for (int i = 0; i < 3; i++) {
			int a = nx[i], b = ny[i];
			if (a < b) b -= a, a += a;
			else if (a > b) a -= b, b += b;
			else continue;
			int c = sum - a - b;
			int X = min(min(a, b), c);
			int Y = max(max(a, b), c);

			if (!visit[X][Y]) {
				q.push(make_pair(X, Y));
				visit[X][Y] = true;
			}
		}
	}

	cout << 0 << endl;

	return 0;
}