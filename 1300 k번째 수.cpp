#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int left = 1, right = K, mid, ans;  //right = K�� �����ϴ� ������ K��° ���� �׻� K���� �۰ų� ���� ����.

	while (left <= right) {
		long long count = 0;
		mid = (left + right) / 2;

		//�� i��°�ٸ��� mid���� ���� ���� ������ �����ش�. ���� N�� �� �۴ٸ� N�� ���Ѵ�.
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