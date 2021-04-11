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

	//�����佺�׳׽��� ü Ȱ��
	long long n = 2;
	while (n * n <= maxNum) {
		long long squareNum = n * n;

		//���� �� �������� �ּҰ� ã��
		long long t = minNum / squareNum;

		//0���� ������������ �ʴ´ٸ� +1����
		if (minNum % squareNum != 0) t++;

		//�ش� ���������� �������ٸ� true�� �����
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