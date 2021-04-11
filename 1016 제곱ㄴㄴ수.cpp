#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int main() {
	long long minNum, maxNum;

	cin >> minNum >> maxNum;

	vector<bool> arr(maxNum - minNum + 1, false);

	//에라토스테네스의 체 활용
	long long n = 2;
	while (n * n <= maxNum) {
		long long squareNum = n * n;

		//범위 내 나눠지는 최소값 찾기
		long long t = minNum / squareNum;

		//0으로 나눠떨어지지 않는다면 +1증가
		if (minNum % squareNum != 0) t++;

		//해당 제곱근으로 나눠진다면 true로 만들기
		for (long long i = t * squareNum; i <= maxNum; i += squareNum) {
			if (arr[i - minNum] == false)
				arr[i - minNum] = true;
		}

		n++;
	}

	int ans = 0;
	for (int i = 0; i < maxNum - minNum + 1; ++i) {
		if (arr[i] == false)
			ans++;
	}
	cout << ans << endl;

	return 0;
}