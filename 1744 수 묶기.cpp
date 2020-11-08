#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int N, sum = 0;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int left = 0, right = N - 1;

	for (; left < right; left += 2) {
		if (arr[left] < 1 && arr[left + 1] < 1)
			sum += (arr[left] * arr[left + 1]);
		else
			break;
	}

	for (; left < right; right -= 2) {
		if (arr[right] > 1 && arr[right - 1] > 1)
			sum += (arr[right] * arr[right - 1]);
		else
			break;
	}

	for (; left <= right; ++left) {
		sum += arr[left];
	}

	cout << sum << endl;

	return 0;
}