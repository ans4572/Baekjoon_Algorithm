#include<iostream>
#include<cstring>

using namespace std;

long long cache[101][10]; //첫번째는 자릿수, 두번째는 그 자릿수에서 나올 수 있는 개수
long long mod = 1000000000;

int main()
{
	int N;
	cin >> N;

	memset(cache, -1, sizeof(cache));

	//첫번째는 특이케이스이므로 따로 초기화
	cache[1][0] = 0;
	for (int i = 1; i <= 9; ++i)
		cache[1][i] = 1;

	//두번째부터는 N까지 반복문을 돌면서 각 자릿수와 나올 수 있는 수를 조합하여 계산
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			//i 자릿수에서 0이 나올 수 있는 개수는 i-1 자릿수에서 1이 나올 수 있는 개수와 같다.
			if (j == 0)
				cache[i][j] = cache[i - 1][j + 1];
			//i 자릿수에서 9가 나올 수 있는 개수는 i-1 자릿수에서 8이 나올 수 있는 개수와 같다.
			else if (j == 9)
				cache[i][j] = cache[i - 1][j - 1];
			else
				cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % mod;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; ++i)
		sum += cache[N][i];

	cout << sum % mod << endl;

	return 0;
}