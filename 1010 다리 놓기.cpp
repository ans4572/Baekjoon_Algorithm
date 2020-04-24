#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[30][30];

int combi(int n, int m) {
	if (m == 0 || n == m) {
		dy[n][m] = 1;
	}
	if (dy[n][m] != 0) {
		return dy[n][m];
	}
	else {
		return dy[n][m] = combi(n - 1, m) + combi(n - 1, m - 1);
	}
}

int main() {
	int T, N, M;
	long long ans;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		cout << combi(M,N) << endl;  //조합을 활용하면 된다.
	}

	return 0;
}