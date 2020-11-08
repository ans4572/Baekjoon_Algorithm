#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int N, K, W = 500;
int kit[9];
bool visit[9];
int ans = 0;

void DFS(int day) {
	if (day == N) {
		//마지막 사용하지 않은 키트 찾아서 결과 판별
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && W + kit[i] - K >= 500) {
				ans++;
			}
		}
	}
	else {
		//백트래킹 활용
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && W + kit[i] - K >= 500) {
				visit[i] = true;
				W += (kit[i] - K);
				DFS(day + 1); 

				visit[i] = false;
				W -= (kit[i] - K);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		cin >> kit[i];
	}

	DFS(1);

	cout << ans << endl;

	return 0;
}