#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int main() {
	int T, N;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N;

		bool flag = true;
		int current, next;
		vector<string> phone(N);

		for (int i = 0; i < N; ++i) {
			cin >> phone[i];
		}

		sort(phone.begin(), phone.end());

		for (int i = 0; i < N - 1; ++i) {
			current = phone[i].length();
			next = phone[i + 1].length();

			if (current >= next)
				continue;
			else if (phone[i + 1].substr(0, current) == phone[i]) {
				flag = false;
				cout << "NO" << endl;
				break;
			}
		}

		if (flag)
			cout << "YES" << endl;
	}

	return 0;
}