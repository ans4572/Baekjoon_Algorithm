#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//실직적 약수들의 합을 반환하는 함수
int SOD(int n) {
	long long sum = 0;

	for (long long i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			sum += i;
			if (n / i != i)
				sum += (n / i);
		}
	}

	return sum;
}

//1~n까지 SOD들의 합을 반환하는 함수 
int CSOD(int n) {
	long long sum = 0;
	for (long long i = 1; i <= n; ++i) {
		sum += SOD(i);
		sum %= 1000000;
	}

	return sum;
}

int main() {
	int N;
	cin >> N;

	cout << CSOD(N) % 1000000 << endl;

	return 0;
}