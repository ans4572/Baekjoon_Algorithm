#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return b;
}

int main() {
	int N, tmp;
	cin >> N;

	vector<int> arr;

	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	int g;
	for (int i = 1; i < N; ++i) {
		g = gcd(arr[0], arr[i]);
		cout << arr[0] / g << "/" << arr[i] / g << endl;
	}

	return 0;
}