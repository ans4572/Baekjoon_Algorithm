#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int k;
int nums[10][2];  //최대 위치 10개에 대해 최소값/최대값 저장
bool choice[10];   //숫자 0-9 사용 여부 판단 배열
char arr[9];       //부등호 저장 배열, 최대 9개
vector<int> maxNums;
vector<int> minNums;

bool compare(vector<int> a, vector<int> b) {
	for (int i = 0; i < k + 1; ++i) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;
	}
}

void grid(int n, vector<int> num) {
	if (n == k + 1) {
		for (int i = 0; i < k + 1; ++i) {
			if (compare(maxNums, num)) maxNums = num;
			if (compare(num, minNums)) minNums = num;
		}
	}
	else {
		for (int i = nums[n][0]; i <= nums[n][1]; ++i) {
			if (choice[i] == false) {
				if ((n == 0) || (n > 0 && (arr[n-1] == '<' && num[n - 1] < i) || (arr[n-1] == '>' && num[n - 1] > i))) {
					choice[i] = true;
					num.push_back(i);
					grid(n + 1, num);
					num.pop_back();
					choice[i] = false;
				}
			}
		}
	}
	return;
}

int main() {
	cin >> k;

	for (int i = 0; i < k; ++i)
		cin >> arr[i];

	int minNum, maxNum;
	char left, right;
	for (int i = 0; i < k + 1; ++i) {
		minNum = 0, maxNum = 9;
		if (i != 0) left = arr[i - 1];
		if (i != k) right = arr[i];

		//왼쪽 탐색
		for (int j = i - 1; j >= 0; --j) {
			if (left != arr[j]) break;

			if (arr[j] == '<') minNum++;
			else maxNum--;
		}

		//오른쪽 탐색
		for (int j = i; j < k; ++j) {
			if (right != arr[j]) break;

			if (arr[j] == '<') maxNum--;
			else minNum++;
		}

		nums[i][0] = minNum;
		nums[i][1] = maxNum;
	}

	//최대값, 최소값 벡터 초기화
	for (int i = 0; i < k + 1; ++i) {
		minNums.push_back(9 - i);
		maxNums.push_back(i);
	}

	vector<int> num;
	grid(0, num);

	for (int i = 0; i < k + 1; ++i) cout << maxNums[i];
	cout << endl;
	for (int i = 0; i < k + 1; ++i) cout << minNums[i];
	
	return 0;
}