#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int dy[100001];

int main() {
	cin >> N;

	dy[0] = 1;
	dy[1] = 3;
	for (int i = 2; i <= N; ++i) {
		dy[i] = (dy[i - 1] * 2 + dy[i - 2]) % 9901;
	}

	cout << dy[N] << endl;

	return 0;
}