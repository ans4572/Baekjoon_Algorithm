#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int N;

	cin >> N;

	vector<int> level(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> level[i];
	}

	int count = 0;
	for (int i = N; i > 1; --i) {
		if (level[i - 1] >= level[i]) {
			count += (level[i - 1] - (level[i]-1));
			level[i - 1] = level[i] - 1;
		}
	}

	cout << count << endl;

	return 0;
}