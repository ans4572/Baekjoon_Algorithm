#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, ans = 0;
	cin >> N;

	int digit = 1, sum = 0, num = 9;
	while (sum + num < N) {
		ans += num * digit;
		sum += num;
		digit++;
		num *= 10;
	}
	ans += ((N - sum)*digit);

	cout << ans << endl;

	return 0;
}