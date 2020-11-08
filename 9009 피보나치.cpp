#include <iostream>
#include <algorithm>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int fibo[45] = { 0,1 };

int main() {
	int T;
	cin >> T;

	for (int i = 2; i < 45; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int n, t, sum;
	vector<int> arr;
	for (int i = 0; i < T; ++i) {
		cin >> n;

		bool arr[45] = { false };
		for (int i = 44; i > 0; --i) {
			if (fibo[i] <= n) {
				n -= fibo[i];
				arr[i] = true;
			}
		}

		for (int i = 1; i < 45; ++i) {
			if (arr[i])
				cout << fibo[i] << " ";
		}
		cout << endl;
	}

	return 0;
}