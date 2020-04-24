#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[1001];  //dy[n]: 1~n까지 증가 부분 수열 중 가장 큰 값 

int main() {
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		dy[i] = arr[i];  //자기 자신이 가장 큰 값으로 초기화 
	}

	//2부터 N까지 
	//앞으로 하나씩 arr[i]와 arr[j]를 비교하면서 arr[i]가 더 크다면
	//dy[i]는 dy[j] + arr[i]와 dy[i] 중 더 큰 값으로 갱신한다.
	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			if (arr[i] > arr[j])
				dy[i] = max(dy[j] + arr[i], dy[i]);
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