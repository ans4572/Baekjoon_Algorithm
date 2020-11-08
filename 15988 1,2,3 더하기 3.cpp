#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

long long dy[1000001];  //dy[N]: N의 방법의 수
int const mod = 1000000009;

long long cal(int n) {
	if (dy[n] != 0)
		return dy[n];
	else {
		return dy[n] = (cal(n - 1) + cal(n - 2) + cal(n - 3)) % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;
	
	dy[1] = 1;
	dy[2] = 2;
	dy[3] = 4;
	dy[4] = 7;
	for (int i = 0; i < T; ++i) {
		cin >> n;

		if (dy[n] != 0)
			cout << dy[n] << endl;
		else {
			cout << cal(n) << endl;
		}
	}

	return 0;
}