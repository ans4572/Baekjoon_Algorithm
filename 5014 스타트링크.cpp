#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	int F, S, G, U, D, ans = 0;
	cin >> F >> S >> G >> U >> D;

	if (S == G) {
		cout << 0 << endl;
		return 0;
	}
	else if (U == 0 || D == 0) {
		cout << "use the stairs" << endl;
		return 0;
	}

	vector<int> count(F + 1, -1);
	queue<int> q;
	q.push(S);
	count[S] = 0;

	while (!q.empty()) {
		int floor = q.front();
		q.pop();

		if (floor - D >= 1 && count[floor - D] == -1) {
			count[floor - D] = count[floor] + 1;
			q.push(floor - D);
		}
		if (floor + U >= 1 && count[floor + U] == -1) {
			count[floor + U] = count[floor] + 1;
			q.push(floor + U);
		}
	}

	if (count[G] == -1)
		cout << "use the stairs" << endl;
	else
		cout << count[G] << endl;

	return 0;
}
