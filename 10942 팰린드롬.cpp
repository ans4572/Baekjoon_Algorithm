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
int dp[2001][2001];  //dp[a][b]: a���� b���� �Ӹ�����̶�� 1, �ƴ϶�� 0

int answer(int a, int b) {
	//�̹� ���� ���
	if (dp[a][b] != -1)
		return dp[a][b];

	//���� arr���� �ٸ� ���� �Ӹ���� X
	if (arr[a] != arr[b])
		return dp[a][b] = 0;
	else {
		//a�� b�� ���̰� 1�̰ų� 2�� ���� �Ӹ����
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

	//dp�迭 �ʱ�ȭ
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