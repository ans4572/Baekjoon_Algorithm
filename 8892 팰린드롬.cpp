#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool palindrome(string a,string b) {
	string c = a + b;
	
	for (int i = 0; i < c.length() / 2; ++i) {
		if (c[i] != c[c.length() - 1 - i]) {
			return false;
		}
	}

	return true;
}

int main() {
	int T;
	cin >> T;

	for (int test = 0; test < T; ++test) {
		bool finish = false;
		int k;
		cin >> k;

		vector<string> arr(k);
		for (int i = 0; i < k; ++i) 
			cin >> arr[i];

		for (int i = 0; i < k; ++i) {
			for (int j = i + 1; j < k; ++j) {
				if (palindrome(arr[i], arr[j])) {
					finish = true;
					cout << arr[i] + arr[j] << endl;
					break;
				}
				if (palindrome(arr[j], arr[i])) {
					finish = true;
					cout << arr[j] + arr[i] << endl;
					break;
				}
			}

			if (finish)
				break;
		}

		if(!finish)
			cout << 0 << endl;
	}

	return 0;
}