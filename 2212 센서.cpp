#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, ans = 0;
	cin >> N;
	cin >> K;

	if (K >= N) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> arr(N);     //입력 센서들 위치
	vector<int> diff(N-1);  //센서들간 차이
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());  //정렬

	for (int i = 0; i < N - 1; ++i) {
		diff[i] = arr[i + 1] - arr[i];
	}

	sort(diff.begin(), diff.end()); //정렬

	//(집중국 개수 - 1) 만큼 가장 긴 거리를 제거 가능
	for (int i = 0; i < N - 1 - (K-1); ++i) {
		ans += diff[i];
	}

	cout << ans << endl;

	return 0;
}