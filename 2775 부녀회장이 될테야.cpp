#include<iostream>

using namespace std;

int residents(int k, int n) {
	int num = 0;
	if (k == 0) {
		return n;
	}
	else {
		for (int i = 1; i <= n; i++) {
			num += residents(k - 1, i);
		}
		return num;
	}
}

int main()
{
	int T;
	cin >> T;
	int k, n;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << residents(k, n) << endl;
	}

	return 0;
}