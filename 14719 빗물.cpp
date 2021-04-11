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
		//���� ����� ���ݱ��� ���� ū ��Ϻ��� �� ũ�ų� ���� ��� ������ ����
		if (arr[maxIndex] <= arr[i]) {
			//����
			for (int j = maxIndex + 1; j < i; ++j) {
				ansArr[j] = arr[maxIndex];
			}
			maxIndex = i;  
		}
		//���� ��� ���� ū �ε���+1 ���� i���� �� ���� ����� �ִ� ��� ������ ����
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