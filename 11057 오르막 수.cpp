#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[1001][10];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 10; ++i)
		dy[1][i] = 1;

	for (int i = 2; i <= N; ++i) {
		dy[i][0] = 1;
		for (int j = 1; j < 10; ++j) {
			dy[i][j] = (dy[i][j-1] + dy[i-1][j]) % 10007;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; ++i)
		ans = (ans + dy[N][i]) % 10007;

	cout << ans % 10007 << endl;

	return 0;
}