#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int left = 0, right = 0, mid = 0;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
		right += arr[i];        //오른쪽 경계는 써야할 날들의 모든 합
		if (left < arr[i]) left = arr[i];  //왼쪽 경계는 가장 큰값이 된다.
	}

	int ans = right;
	while (left <= right) {
		if (mid == (left + right) / 2) break;

		mid = (left + right) / 2;

		int money = 0, count = 0;
		for (int i = 0; i < N; ++i) {
			//돈이 부족한 경우 새로 인출
			if (money < arr[i]) {
				count++;
				money = mid - arr[i];
			}
			else
				money -= arr[i];
		}

		if (count > M) left = mid;
		else if (count <= M) {
			ans = mid;
			right = mid;
		}
	}

	cout << ans << endl;

	return 0;
}