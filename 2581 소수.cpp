#include<iostream>

using namespace std;

bool isPrime(int n) {
	bool prime = true;
	if (n != 1) {
		for (int j = 2; j < n; j++) {
			if (n%j == 0) {
				prime = false;
				break;
			}
		}
		if (prime == true)
			return true;
	}
	return false;
}

int main()
{
	int M, N;
	cin >> M;
	cin >> N;
	int sum = 0,min=0;
	bool exist = false;
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			if (min == 0) {
				min = i;
				exist = true;
			}
			sum += i;
		}
	}
	if (exist == false)
		cout << -1 << endl;
	else {
		cout << sum << endl << min << endl;
	}

	return 0;
}