#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int left = 1, right = K, mid, ans;  //right = K로 설정하는 이유는 K번째 수는 항상 K보다 작거나 같기 때문.

	while (left <= right) {
		long long count = 0;
		mid = (left + right) / 2;

		//각 i번째줄마다 mid보다 작은 수의 개수를 더해준다. 만약 N이 더 작다면 N을 더한다.
		for (int i = 1; i <= N; ++i) {
			count += min(mid / i, N);
		}

		if (count < K) left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}

	cout << ans << endl;

	return 0;
}