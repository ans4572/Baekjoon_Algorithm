#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int ans = 0;

void collect(vector<int> w, int sum) {
	if (w.size() == 2) {
		if (ans < sum)
			ans = sum;
	}
	else {
		for (int i = 1; i < w.size() - 1; ++i) {
			vector<int> temp;
			for (int j = 0; j < w.size(); ++j) {
				if(i != j)
					temp.push_back(w[j]);
			}
			collect(temp, sum + w[i - 1] * w[i + 1]);
		}
	}

	return;
}

int main() {
	int N;
	cin >> N;

	vector<int> vec(N);

	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}

	collect(vec, 0);

	cout << ans << endl;

	return 0;
}