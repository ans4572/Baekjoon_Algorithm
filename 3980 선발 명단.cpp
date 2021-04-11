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

int player[11][11];
int ans = 0;
bool visit[11];

//백트래킹 활용
void DFS(int index, int sum) {
	if (index == 11) {
		if (ans < sum)
			ans = sum;
	}
	else {
		for (int i = 0; i < 11; ++i) {
			if (player[i][index] > 0 && !visit[i]) {
				visit[i] = true;
				DFS(index + 1, sum + player[i][index]);
				visit[i] = false;
			}
		}
	}
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int C;
	cin >> C;

	for (int test = 0; test < C; ++test) {
		memset(player, 0, sizeof(player));
		ans = 0;

		for (int i = 0; i < 11; ++i) {
			for (int j = 0; j < 11; ++j) {
				cin >> player[i][j];
			}
		}

		DFS(0, 0);

		cout << ans << "\n";
	}

	return 0;
}