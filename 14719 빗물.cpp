#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int arr[501];
int ansArr[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int H, W;
	int sum = 0, ans = 0;
	cin >> H >> W;

	for (int i = 0; i < W; ++i) {
		cin >> arr[i];
		sum += arr[i];
		ansArr[i] = arr[i];
	}
	
	int maxIndex = 0;

	for (int i = 1; i < W; ++i) {
		//현재 블록이 지금까지 가장 큰 블록보다 더 크거나 같은 경우 빗물이 고임
		if (arr[maxIndex] <= arr[i]) {
			//갱신
			for (int j = maxIndex + 1; j < i; ++j) {
				ansArr[j] = arr[maxIndex];
			}
			maxIndex = i;  
		}
		//작은 경우 가장 큰 인덱스+1 부터 i까지 더 작은 블록이 있는 경우 빗물이 고임
		else {
			for (int j = maxIndex + 1; j < i; ++j) {
				if(ansArr[j] < arr[i])
					ansArr[j] = arr[i];
			}
		}
	}

	for (int i = 0; i < W; ++i) {
		ans += ansArr[i];
	}

	cout << ans - sum << endl;

	return 0;
}