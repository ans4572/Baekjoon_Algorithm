#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> arr(K + 1, 0);
	int w, v;
	for (int i = 0; i < N; ++i) {
		cin >> w >> v;

		for (int j = K; j >= w; --j) {
			arr[j] = max(arr[j], arr[j - w] + v);
		}
	}

	cout << arr[K] << endl;

	return 0;
}