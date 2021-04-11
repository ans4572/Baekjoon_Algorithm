#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;

	int input[1024];

	int count = pow(2, K);

	for (int i = 1; i < count; ++i) {
		cin >> input[i];
	}

	int temp = pow(2, K - 1);
	int inteval = pow(2, K);
	for (int i = 1; i <= K; ++i) {
		for (int j = 0; j < pow(2, i - 1); ++j) {
			cout << input[temp + j * inteval] << " ";
		}
		cout << endl;
		temp /= 2;
		inteval /= 2;
	}

	return 0;
}

