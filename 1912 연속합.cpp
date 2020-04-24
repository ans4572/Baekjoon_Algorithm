#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[100001];  //dp[n]: ���� n������ �ִ� ������

int main() {
	int N;
	cin >> N;
	
	vector<int> arr(N + 1);

	for (int i = 1; i <= N; ++i)
		scanf("%d", &arr[i]);

	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	//�ִ밪 ã��
	int maxx = dp[1];
	for (int i = 1; i <= N; i++) {
		if (dp[i] > maxx) maxx = dp[i];
	}

	cout << maxx << endl;

	return 0;
}