#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	vector<int> arr(9);

	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr.begin(), arr.end());

	int diff = sum - 100;
	int notA, notB;
	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (arr[i] + arr[j] == diff) {
				notA = i;
				notB = j;
			}
		}
	}

	for (int i = 0; i < 9; ++i) {
		if (arr[i] != arr[notA] && arr[i] != arr[notB])
			cout << arr[i] << endl;
	}

	return 0;
}