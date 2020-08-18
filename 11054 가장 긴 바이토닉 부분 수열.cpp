#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	vector<int> increase(N,1);   //increase[x]: 1에서 x까지 증가하는 개수 
	vector<int> backIncrease(N,1);   //backIncrease[x]: N-1에서 x까지 증가하는 개수

	for (int i = 1; i < N; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (arr[i] > arr[j]) {
				increase[i] = max(increase[i], increase[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; --i) {
		for (int j = i + 1; j < N; ++j) {
			if (arr[i] > arr[j]) {
				backIncrease[i] = max(backIncrease[i], backIncrease[j] + 1);
			}
		}
	}

	int max = 0;
	for (int i = 0; i < N; ++i) {
		if (max < increase[i] + backIncrease[i])
			max = increase[i] + backIncrease[i];
	}

	cout << max - 1 << endl;

	return 0;
}