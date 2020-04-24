#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[1001];  //dy[n] 에서 1 ~ n까지 최장 길이 

int main() {
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		dy[i] = 1;
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			//arr[i]가 비교하는 arr[j]보다 클 경우 
			//해당 dy[j] + 1 과 현재 dy[i]를 비교하여 큰 것으로 갱신한다.
			if (arr[i] > arr[j]) 
				dy[i] = max(dy[j] + 1, dy[i]);
		}
	}

	int max = 0;
	for (int i = 1; i <= N; ++i) {
		if (max < dy[i])
			max = dy[i];
	}

	cout << max << endl;

	return 0;
}