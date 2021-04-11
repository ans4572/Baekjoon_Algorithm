#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int arr[2001];
int dp[2001][2001];  //dp[a][b]: a부터 b까지 팰린드롬이라면 1, 아니라면 0

int answer(int a, int b) {
	//이미 구한 경우
	if (dp[a][b] != -1)
		return dp[a][b];

	//둘의 arr값이 다른 경우는 팰린드롬 X
	if (arr[a] != arr[b])
		return dp[a][b] = 0;
	else {
		//a와 b의 차이가 1이거나 2인 경우는 팰린드롬
		if (b - a <= 2) {
			return dp[a][b] = 1;
		}
		else {
			return dp[a][b] = answer(a + 1, b - 1);
		}
	}
}

int main() {
	int N, M;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &arr[i]);
	}

	//dp배열 초기화
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; ++i)
		dp[i][i] = 1;

	cin >> M;
	int a, b;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);

		cout << answer(a, b) << "\n";
	}

	return 0;
}