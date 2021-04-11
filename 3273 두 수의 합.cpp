#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	cin >> x;

	sort(arr.begin(), arr.end());

	int left = 0, right = n - 1;
	int ans = 0;

	while (left < right) {
		if (arr[left] + arr[right] == x) {
			ans++;
			left++;
			right--;
		}
		else if (arr[left] + arr[right] > x) 
			right--;
		else
			left++;
	}

	cout << ans << endl;

	return 0;
}