/*
일반 거듭제곱 함수로는 시간내로 풀지 못하므로 분할 정복으로 풀어야함
절반씩 쪼개며 계산하고 return을 할 때 값은 각 곱하는 수마다 %mod를 해줘야함.
*/
#include<iostream>

using namespace std;

long long myPow(long long base, long long exp, long long mod)
{
	//기저사례
	if (exp == 0)
		return 1;

	long long half = myPow(base, exp / 2, mod);
	if (exp % 2 == 0)
	{
		return ((half % mod) * (half % mod)) % mod;
	}
	else
		return ((base * half % mod) * (half % mod)) % mod;
}

int main()
{
	long long A, B, C;
	cin >> A >> B >> C;

	cout << myPow(A,B,C) << endl;

	return 0;
}