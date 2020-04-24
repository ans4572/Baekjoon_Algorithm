#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j >= 1; --j) {
			if (i*j <= N)
				sum++;
		}
	}

	cout << sum << endl;

	return 0;
}