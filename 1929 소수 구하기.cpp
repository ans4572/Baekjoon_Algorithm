#include<iostream>

using namespace std;

//소수 판별 함수
//j*j <= n 을 한 이유는 소수 판별을 하기 위해 2부터 그 수 전까지를 모조리 나누어 보면 시간 초과가 된다. 
//시간을 줄이는 가장 간단한 방법으로는 그 수의 제곱근까지만 나누어 보는 것.
//만일 어떤 자연수 x에 sqrt(x)보다 큰 소인수가 존재한다면, x를 sqrt(x)로 나눈 값은 
//sqrt(x)보다 작아야 하기 때문에, 2부터 순차적으로 i를 증가시키는 동안 이미 그 수로 나누어보았을 것이기 때문
bool isPrime(int n) {
	bool prime = true;
	if (n != 1) {
		for (int j = 2; j*j <= n; j++) {
			if (n%j == 0) {
				prime = false;
				break;
			}
		}
		if (prime == true)
			return true;
	}
	return false;
}

int main()
{
	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			cout << i <<"\n";
		}
	}

	return 0;
}