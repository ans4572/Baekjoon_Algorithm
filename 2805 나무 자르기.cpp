#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long N, M;
	cin >> N >> M;

	long long mid = 0, left = 0, right=0, sum;
	vector<int> trees(N);
	for (long long i = 0; i < N; ++i) {
		cin >> trees[i];
		if (right < trees[i]) right = trees[i];
	}

	while (left <= right) {
		if (mid == (left + right) / 2) break;  //더 이상 변동이 없는 경우

		mid = (left + right) / 2;
		sum = 0;

		for (long long i = 0; i < N; ++i) {
			if (mid >= trees[i]) continue;
			else sum += (trees[i] - mid);
		}

		if (sum < M) right = mid;
		else if (sum > M) left = mid;
		else if (sum == M) break;
	}

	cout << mid << endl;

	return 0;
}