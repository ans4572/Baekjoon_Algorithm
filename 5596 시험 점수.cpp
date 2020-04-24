#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int p1_sum = 0,p2_sum=0;
	int tmp;
	for (int i = 0; i < 4; ++i) {
		cin >> tmp;
		p1_sum += tmp;
	}
	for (int i = 0; i < 4; ++i) {
		cin >> tmp;
		p2_sum += tmp;
	}
	if (p1_sum > p2_sum)
		cout << p1_sum << endl;
	else
		cout << p2_sum << endl;

	return 0;
}