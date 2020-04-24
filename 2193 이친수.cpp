#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//dy[n][m] n: 마지막 숫자(0 or 1) / m:길이
long long dy[2][91];

int main() {
	int N;
	cin >> N;
	dy[0][1] = 0;
	dy[1][1] = 1;

	//0으로 끝났다면 다음에 올 수 있는 숫자는 0과 1이다.
	//1로 끝났다면 다음에 올 수 있는 숫자는 0밖에 없다.
	for (int i = 2; i <= N; ++i) {
		dy[0][i] = dy[0][i - 1] + dy[1][i - 1];
		dy[1][i] = dy[0][i - 1];
	}

	cout << dy[0][N] + dy[1][N] << endl;

	return 0;
}