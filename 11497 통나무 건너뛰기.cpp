#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int T;
	cin >> T;

	int N;
	vector<int> L;
	int arr[100001];
	for (int t = 0; t < T; ++t) {
		cin >> N;

		L.resize(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> L[i];
		}

		sort(L.begin(), L.end());

		for (int i = 1; i <= N / 2; ++i) {
			arr[i] = L[i * 2 - 1];
			arr[N - i + 1] = L[i * 2];
		}
		if (N % 2 == 1) {
			arr[(N / 2) + 1] = L[N];
		}
		
		int diff = 0;
		for (int i = 1; i < N; ++i) {
			if (diff < abs(arr[i] - arr[i + 1])) {
				diff = abs(arr[i] - arr[i + 1]);
			}
		}
		if (diff < abs(arr[1] - arr[N])) {
			diff = abs(arr[1] - arr[N]);
		}

		cout << diff << endl;
	}

	return 0;
}