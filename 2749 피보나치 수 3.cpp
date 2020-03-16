/*
일반적인 피보나치 재귀 함수의 시간복잡도는 O(2^n)이다.
이 문제에서는 n의 범위가 무척 크므로 일반적인 방식으로는 시간초과가 되며
피사노 주기(Pisano Period)를 사용하여야한다.
피사노 주기란 피보나치 수를 K로 나눈 나머지는 항상 주기를 가지게 되는데 이를 피사노 주기라 한다.
주기의 길이가 P이면, N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M을 나눈 나머지와 같다.
M = 10^k 일 때, k > 2 라면, 주기는 항상 15 × 10^(k-1) 이다.
*/
#include<iostream>

using namespace std;

const int mod = 1000000; //나머지
const int p = mod / 10 * 15; //주기

int fibo[p] = { 0,1 };

int main()
{
	long long n;
	cin >> n;

	for (int i = 2; i < p; ++i)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod; //매번 나머지로 나눠줘야함
	}

	cout << fibo[n%p] << endl;

	return 0;
}