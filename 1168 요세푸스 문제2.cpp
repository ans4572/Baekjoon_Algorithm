#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> vec;
	for (int i = 1; i <= N; ++i)
		vec.push_back(i);

	int index = -1;
	int remain = N;
	
	cout << "<";

	for (int i = 0; i < N; ++i) {
		index = (index + K) % remain;

		cout << vec[index];
		vec.erase(vec.begin() + index);
		index--; remain--;

		if (i == N - 1) cout << ">" << endl;
		else cout << ", ";
	}

	return 0;
}