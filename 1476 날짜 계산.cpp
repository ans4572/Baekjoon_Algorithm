#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int E, S, M;
	cin >> E >> S >> M;

	int ans = 1;
	int e = 1, s = 1, m = 1;

	while (1) {
		if (e == E && s == S && m == M) {
			break;
		}

		e++; s++; m++;
		ans++;

		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}

	cout << ans << endl;

	return 0;
}