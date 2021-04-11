#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	long long N;
	long long arr[2][2] = { {1,1},{1,0} };
	long long ans[2][1] = { {1},{0} };

	cin >> N;

	if (N <= 1) {
		cout << N << endl;
		return 0;
	}

	while (N > 0) {
		//N이 홀수 때마다 따로 추가 계산하여야 함
		if (N % 2 == 1) {
			long long temp[2][1] = { {arr[0][0] * ans[0][0] + arr[0][1] * ans[1][0]},
									 {arr[1][0] * ans[0][0] + arr[1][1] * ans[1][0]} };

			ans[0][0] = temp[0][0] % 1000000007;
			ans[1][0] = temp[1][0] % 1000000007;
		}

		long long temp[2][2] = { {arr[0][0] * arr[0][0] + arr[0][1] * arr[1][0], arr[0][0] * arr[0][1] + arr[0][1] * arr[1][1]},
								 {arr[0][0] * arr[1][0] + arr[1][0] * arr[1][1], arr[0][1] * arr[1][0] + arr[1][1] * arr[1][1]} };

		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				arr[i][j] = temp[i][j] % 1000000007;
			}
		}

		N /= 2;
	}

	cout << ans[1][0] << endl;

	return 0;
}