#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
		cin >> B[i];

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end());

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += A[i] * B[i];
	}

	cout << ans << endl;

	return 0;
}