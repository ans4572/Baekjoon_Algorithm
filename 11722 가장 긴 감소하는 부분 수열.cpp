#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dy(1001,1);

int main() {
	int N;
	cin >> N;
	vector<int> arr(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	int ans = dy[1];
	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j > 0; --j) {
			if (arr[i] < arr[j]) {
				dy[i] = max(dy[j] + 1, dy[i]);
			}
		}
		if (ans < dy[i])
			ans = dy[i];
	}

	cout << ans << endl;

	return 0;
}