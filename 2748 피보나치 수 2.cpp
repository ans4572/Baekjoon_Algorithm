#include<iostream>
#include<cstring>

using namespace std;

long long cache[91]; //메모이제이션을 위한 배열

//재귀함수를 이용한 피보나치 함수
long long fibo(long long n)
{
	//기저사례
	if (n <= 1)
		return n;
	long long& ret = cache[n]; //참조형 변수 선언
	//만약 이미 계산하였다면 바로 리턴
	if (ret != -1)
		return ret;
	//아니라면 계산 후 cache배열에 삽입
	else
		return ret = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	long long n;
	cin >> n;
	memset(cache, -1, sizeof(cache)); //cache배열을 -1로 초기화

	cout << fibo(n) << endl;

	return 0;
}