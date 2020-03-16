#include<iostream>

using namespace std;

//소수 판별 함수
bool isPrime(int n) {
	bool prime = true;
	if (n != 1) {
		for (int j = 2; j*j <= n; j++) {
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
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		int x = 0;
		cin >> n;
		while (1) {
			if (isPrime(n / 2 - x) == true && isPrime(n / 2 + x) == true) {
				cout << n / 2 - x << " " << n / 2 + x << endl;
				break;
			}
			x++;
		}
	}

	return 0;
}