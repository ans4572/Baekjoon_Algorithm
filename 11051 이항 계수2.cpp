#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[1001][1001];

int bc(int n, int k) {
	if (k == 0 || n == k) {
		return dy[n][k] = 1;
	}
	if (dy[n][k] != 0) {
		return dy[n][k];
	}
	else {
		return dy[n][k] = (bc(n - 1, k - 1) % 10007 + bc(n - 1, k) % 10007) % 10007;
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	cout << bc(N, K) << endl;

	return 0;
}