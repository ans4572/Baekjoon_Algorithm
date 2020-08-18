#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int left, right, mid;

	cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; ++i) {
		cin >> cards[i];
	}

	//오름차순으로 정렬
	sort(cards.begin(), cards.end());

	cin >> M;
	int num;
	for (int i = 0; i < M; ++i) {
		left = 0, right = N - 1, mid = 0;
		cin >> num;

		if (num == cards[left] || num == cards[right]) {
			cout << 1 << " ";
			continue;
		}

		while (left <= right) {
			if (mid == (left + right) / 2) break;

			mid = (left + right) / 2;

			if (num > cards[mid]) left = mid;
			else if (num < cards[mid]) right = mid;
		}

		if (num == cards[mid]) cout << 1 << " ";
		else cout << 0 << " ";
	}

	return 0;
}