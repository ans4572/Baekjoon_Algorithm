#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[1001];
	int count = 0, num = 1;
	for (int i = 1; i <= 1000; ++i) {
		arr[i] = num;
		count++;

		if (count == num) {
			count = 0;
			num++;
		}
	}

	int start, end, ans = 0;
	cin >> start >> end;

	for (int i = start; i <= end; ++i) {
		ans += arr[i];
	}

	cout << ans << endl;

	return 0;
}