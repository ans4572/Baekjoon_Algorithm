#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int dy[31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	dy[0] = 1;
	dy[1] = 0;
	dy[2] = 3;
	dy[3] = 0;
	dy[4] = 11;

	for (int i = 5; i <= N; ++i) {
		if (i % 2 == 0) {
			dy[i] = dy[i - 2] * 3;

			for (int j = 4; i - j >= 0; j += 2) {
				dy[i] += dy[i - j] * 2;
			}
		}
	}

	cout << dy[N] << endl;

	return 0;
}