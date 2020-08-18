#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> p(N);

	for (int i = 0; i < N; ++i) 
		cin >> p[i];

	sort(p.begin(), p.end());

	int sum = 0;
	int ans = 0;

	for (int i = 0; i < N; ++i) {
		sum += p[i];
		ans += sum;
	}

	cout << ans << endl;

	return 0;
}