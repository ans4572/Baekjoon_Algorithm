#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M, left= 0, right = 1, mid = 0;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (right < arr[i]) right = arr[i];
	}

	cin >> M;

	//이분 탐색 활용
	int sum;
	while (left <= right) {
		if (mid == (left + right) / 2) break;

		sum = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < N; ++i) {
			if (mid <= arr[i]) sum += mid;
			else sum += arr[i];
		}

		if (sum < M) left = mid + 1;
		else if (sum > M) right = mid - 1;
		else break;
	}

	if (sum > M)
		cout << mid - 1 << endl;
	else
		cout << mid << endl;

	return 0;
}