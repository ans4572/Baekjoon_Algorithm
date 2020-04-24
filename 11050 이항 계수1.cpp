#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[11][11];

int DFS(int n, int k) {
	if (n == k || k == 0) {
		return dy[n][k] = 1;
	}
	if (dy[n][k] != 0)
		return dy[n][k];
	else {
		return dy[n][k] = DFS(n - 1, k - 1) + DFS(n - 1, k);
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	cout << DFS(N, K) << endl;

	return 0;
}