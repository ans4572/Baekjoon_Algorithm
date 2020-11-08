#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int N;
	string word;
	cin >> N;

	vector<int> num(26);
	
	for (int i = 0; i < N; ++i) {
		cin >> word;
		int pos = pow(10,word.length() - 1);

		for (int j = 0; j < word.length(); ++j) {
			num[word[j] - 'A'] += pos;
			pos /= 10;
		}
	}

	sort(num.begin(), num.end(), greater<int>());
	int sum = 0, value = 9;
	for (int i = 0; i < 26; ++i) {
		sum += num[i] * value;
		value--;

		if (value == 0) break;
	}

	cout << sum << endl;

	return 0;
}