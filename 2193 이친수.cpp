#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//dy[n][m] n: ������ ����(0 or 1) / m:����
long long dy[2][91];

int main() {
	int N;
	cin >> N;
	dy[0][1] = 0;
	dy[1][1] = 1;

	//0���� �����ٸ� ������ �� �� �ִ� ���ڴ� 0�� 1�̴�.
	//1�� �����ٸ� ������ �� �� �ִ� ���ڴ� 0�ۿ� ����.
	for (int i = 2; i <= N; ++i) {
		dy[0][i] = dy[0][i - 1] + dy[1][i - 1];
		dy[1][i] = dy[0][i - 1];
	}

	cout << dy[0][N] + dy[1][N] << endl;

	return 0;
}