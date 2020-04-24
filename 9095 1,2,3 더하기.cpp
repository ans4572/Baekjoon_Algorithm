#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[11]; //dy[n]에서 1,2,3의 합으로만 n을 만들 수 있는 경우의 수

int Hap(int n) {
	if (dy[n] != 0)
		return dy[n];
	else {
		//경우의 수는 (1+dy[n-1]) + (2+dy[n-2]) + (3+dy[n-3])이다.
		int sum = Hap(n - 1) + Hap(n - 2) + Hap(n - 3);
		return dy[n] = sum;
	}
}

int main() {
	int T,n;
	cin >> T;

	dy[1] = 1;
	dy[2] = 2;
	dy[3] = 4;

	for (int i = 0; i < T; ++i) {
		cin >> n;
		cout << Hap(n) << endl;
	}

	return 0;
}