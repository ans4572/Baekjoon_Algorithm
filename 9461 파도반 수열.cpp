#include<iostream>
#include<cstring> //memset을 위한 헤더

using namespace std;

long long cache[102]; //메모이제이션을 위한 배열

long long padovan(int n)
{
	//기저 사례
	if (n <= 5)
		return cache[n];
	long long& ret = cache[n];
	if (ret != -1)
		return ret;
	else
	{
		return ret = padovan(n - 1) + padovan(n - 5);
	}
}

int main()
{
	int T;
	cin >> T;

	//cache배열 초기화
	memset(cache, -1, sizeof(cache));
	cache[1] = cache[2] = cache[3] = 1;
	cache[4] = cache[5] = 2;

	int N;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		cin >> N;
		cout<<padovan(N)<<"\n";
	}

	return 0;
}