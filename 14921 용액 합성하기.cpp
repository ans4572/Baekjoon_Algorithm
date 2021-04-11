#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int N;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int left = 0, right = N - 1;
	int temp, ans = 200000;

	while (left < right) {
		temp = arr[left] + arr[right];
		if (abs(temp) < abs(ans))
			ans = temp;

		if (abs(arr[left]) < abs(arr[right]))
			right--;
		else
			left++;
	}

	cout << ans << endl;

	return 0;
}