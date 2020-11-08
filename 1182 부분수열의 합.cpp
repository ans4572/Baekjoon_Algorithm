#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int N, S;
int arr[21];
int ans = 0;

void seq(int index, int sum, int count) {
	if (index == N) {
		if (sum == S && count > 0) {
			ans++;
		}
	}
	else {
		seq(index + 1, sum + arr[index], count+1);
		seq(index + 1, sum, count);
	}

	return;
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	seq(0, 0, 0);

	cout << ans << endl;

	return 0;
}