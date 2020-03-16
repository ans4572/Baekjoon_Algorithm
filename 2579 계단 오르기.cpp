#include<iostream>
#include<cstring> //memset을 위한 헤더
#include<algorithm> //max를 위한 헤더

using namespace std;

int stairs[301] = { 0 };
int cache[301]; //메모이제이션을 위한 배열

int main()
{
	int N;
	cin >> N;
	
	memset(cache, -1, sizeof(cache));

	for (int i = 1; i <= N; ++i)
		cin >> stairs[i];

	//세번째 계단까지는 특수케이스이므로 미리 초기화해준다
	cache[1] = stairs[1];
	cache[2] = max(stairs[1] + stairs[2], stairs[2]);
	cache[3] = max(stairs[1], stairs[2])+ stairs[3];

	for (int i = 4; i <= N; ++i)
		cache[i] = max(cache[i - 2], cache[i - 3] + stairs[i - 1]) + stairs[i];
	
	cout << cache[N] << endl;

	return 0;
}