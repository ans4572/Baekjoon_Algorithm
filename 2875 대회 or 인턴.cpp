#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int groupNum, remain = 0;
	if (N >= M * 2)
		groupNum = M;
	else
		groupNum = N / 2;

	remain = N - (groupNum * 2) + M - groupNum;  //�׷�Ἲ �� ������ �л����� ��

	if (remain >= K)  //������ �ο��� ���Ͻ� ���� �ο����� ���� ���
		cout << groupNum << endl;
	else {   //������ �ο��� ���Ͻ� ���� �ο����� ���� ���
		int temp = K - remain;
		if (temp % 3 == 0) temp = temp / 3;
		else temp = (temp / 3) + 1;

		groupNum -= temp;
		if (groupNum <= 0)
			cout << 0 << endl;
		else
			cout << groupNum << endl;
	}

	return 0;
}