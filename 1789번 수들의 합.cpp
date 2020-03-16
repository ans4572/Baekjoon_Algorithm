#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	long long S, sum = 0, now = 1,count = 0;
	cin >> S;

	while (1) {
		if (sum + now > S)
			break;
		sum += now;
		now++;
		count++;
	}

	cout << count << endl;

	return 0;
}