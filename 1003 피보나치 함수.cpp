#include<iostream>
#include<cstring> //memset을 위한 헤더

using namespace std;

long long cache[41]; //메모이제이션을 위한 배열

//재귀함수를 이용한 피보나치 함수
long long fibo(long long n)
{
	//기저사례
	if (n <= 1) 
	{
		cache[n] = n;
		return n;
	}

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
	int T;
	cin >> T;

	memset(cache, -1, sizeof(cache)); //cache배열 값들을 -1로 초기화

	long long N;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		cin >> N;
		
		if (N == 0)
			cout << 1 << " " << 0 << endl;
		else if (N == 1)
			cout << 0 << " " << 1 << endl;
		else
		{
			fibo(N);
			cout << cache[N - 1] << " " << cache[N] << endl;
		}
	}

	return 0;
}