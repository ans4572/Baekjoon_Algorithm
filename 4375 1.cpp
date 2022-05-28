// https://www.acmicpc.net/problem/4375

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>

using namespace std;

int main() {

	int n;
	while (scanf("%d", &n) != EOF) {
		int cnt = 1, ans = 1;
		while (true) {
			if (cnt % n == 0) {
				cout << ans << "\n";
				break;
			}
			else {
				cnt = cnt * 10 + 1;
				cnt %= n;
				ans++;
			}
		}
	}

	return 0;
}