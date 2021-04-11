#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int N;
int board[201][201];
bool visit[201][201];

int dr[6] = { -2,-2,0,0,+2,+2 };
int dc[6] = { -1,+1,-2,+2,-1,+1 };

class state {
public:
	int r, c, count;

	state() {}
	state(int r, int c, int count) {
		this->r = r;
		this->c = c;
		this->count = count;
	}
};

bool inBoard(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}

int main() {
	cin >> N;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	queue<state> q;
	q.push(state(r1, c1, 0));

	int ans = -1;

	while (!q.empty()) {
		state now = q.front();
		q.pop();

		if (now.r == r2 && now.c == c2) {
			ans = now.count;
			break;
		}

		int nextR, nextC;
		for (int i = 0; i < 6; ++i) {
			nextR = now.r + dr[i];
			nextC = now.c + dc[i];

			if (inBoard(nextR, nextC) && !visit[nextR][nextC]) {
				visit[nextR][nextC] = true;
				q.push(state(nextR, nextC, now.count + 1));
			}
		}
	}

	cout << ans << endl;

	return 0;
}