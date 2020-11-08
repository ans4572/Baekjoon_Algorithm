#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int arr[5];

bool pass() {
	for (int i = 0; i < 4; ++i) {
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
			for (int j = 0; j < 5; ++j) {
				cout << arr[j] << " ";
			}
			cout << endl;
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

int main() {
	for (int i = 0; i < 5; ++i) {
		cin >> arr[i];
	}

	while (1) {
		if (pass()) break;
	}

	return 0;
}