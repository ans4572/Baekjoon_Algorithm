#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 0;
	int n;
	for (int i = 0; i < N; i++) {
		bool prime = true;
		cin >> n;
		if (n != 1) {
			for (int j = 2; j < n; j++) {
				if (n%j == 0) {
					prime = false;
					break;
				}
			}
			if (prime == true)
				count++;
		}
	}
	cout << count << endl;

	return 0;
}