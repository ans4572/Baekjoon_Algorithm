#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int p1 = 0, p2 = 0, sum = arr[0], count = 0;

	while (p2 < N) {
		//sum이 M보다 작거나 같다면 p2 증가
		if (sum <= M) {
			if (sum == M) count++;

			p2++;
			if (p2 == N) break;  //만약 p2가 끝에 도달했다면 while문 종료

			sum += arr[p2];
		}
		//sum이 M보다 크다면 p1 증가
		else if (sum > M) {
			sum -= arr[p1];
			p1++;
		}
	}

	cout << count << endl;

	return 0;
}