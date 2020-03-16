#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int sum,tmp;
	cin >> sum;
	for (int i = 0; i < 9; ++i) {
		cin >> tmp;
		sum -= tmp;
	}
	cout << sum << endl;

	return 0;
}