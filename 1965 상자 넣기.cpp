#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N+1);
	vector<int> dy(1001, 1);
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	int ans = 1;
	dy[1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			if(arr[i] > arr[j])
				dy[i] = max(dy[i], dy[j] + 1);
		}
		if (ans < dy[i])
			ans = dy[i];
	}

	cout << ans << endl;

	return 0;
}