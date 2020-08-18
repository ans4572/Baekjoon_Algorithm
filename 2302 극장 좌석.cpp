#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int fibo[41];
int ans = 1;

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	vector<int> fix(M);

	for (int i = 0; i < M; ++i)
		cin >> fix[i];

	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int count = 0;
	int fixIndex = 0;
	for (int i = 1; i <= N; ++i) {
		if (fixIndex < M && i == fix[fixIndex]) {
			ans *= fibo[count];
			count = 0;
			fixIndex++;
		}
		else 
			count++;
		if (i == N) {
			ans *= fibo[count];
		}
	}

	cout << ans << endl;

	return 0;
}