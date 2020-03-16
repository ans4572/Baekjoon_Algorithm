#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> dy(N + 1);

	dy[0] = 0;
	for (int i = 1; i <= N; ++i)
		dy[i] = i;

	int p;
	for (int i = 2; i*i <= N; ++i) {
		p = i * i;
		for (int j = p; j <= N; ++j) {
			dy[j] = min(dy[j], dy[j - p] + 1);
		}
	}

	cout << dy[N] << endl;

	return 0;
}