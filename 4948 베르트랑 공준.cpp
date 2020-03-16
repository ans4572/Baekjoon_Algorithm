#include<iostream>

using namespace std;

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
	int n=1;
	while (n != 0) {
		cin >> n;
		if (n == 0)
			break;

		int count = 0;
		for (int i = (n + 1); i <= 2 * n; i++) {
			if (isPrime(i))
				count++;
		}
		cout << count << endl;
	}

	return 0;
}