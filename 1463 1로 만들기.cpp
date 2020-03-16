#include<iostream>
#include<cstring>   //memset을 위한 헤더
#include<algorithm> //min을 위한 헤더

using namespace std;

int cache[1000001];

int main()
{
	int N;
	cin >> N;

	memset(cache, -1, sizeof(cache));

	//1,2,3은 특수 케이스로 따로 초기화
	cache[1] = 0;
	cache[2] = cache[3] = 1;

	//4부터 반복문을 돌면서 가장 연산을 적게 하는 횟수를 저장한다.
	for (int i = 4; i <= N; ++i)
	{
		//3과 2로 둘 다 나눌 수 있을 때
		if (i % 3 == 0 && i % 2 == 0)
			cache[i] = min(cache[i / 3], min(cache[i / 2], cache[i - 1])) + 1;
		//3으로 나눌 수 있을 때
		else if (i % 3 == 0)
			cache[i] = min(cache[i / 3], cache[i - 1]) + 1;
		//2로 나눌 수 있을 때
		else if (i % 2 == 0)
			cache[i] = min(cache[i / 2], cache[i - 1]) + 1;
		//-1밖에 할 수 없을 때
		else
			cache[i] = cache[i - 1] + 1;
	}

	cout << cache[N] << endl;

	return 0;
}