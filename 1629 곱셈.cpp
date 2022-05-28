// https://www.acmicpc.net/problem/1629

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>

using namespace std;

long long A, B, C;

// 횟수인 b가 1이 될때까지 분할정복 진행
int cal(long long a, long long b) {
	if (b == 1) return a % C;
	else {
		long long c = cal(a, b / 2);
		c = (c * c) % C;

		// b가 홀수인 경우 한번 더 곱해주기
		if (b % 2) c = (c * a) % C;

		return c;
	}
}

int main() {
	cin >> A >> B >> C;

	cout << cal(A, B) << endl;

	return 0;
}