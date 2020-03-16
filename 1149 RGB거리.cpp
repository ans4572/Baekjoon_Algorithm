#include<iostream>
#include<cstring> //memset을 사용하기 위한 헤더
#include<algorithm> //min을 사용하기 위한 헤더

using namespace std;

int N;
int red[1001], green[1001], blue[1001]; //색깔별 배열
int cache[1001][3]; //메모이제이션을 위한 배열

int main()
{
	cin >> N;

	for (int home = 1; home <= N; ++home)
	{
		cin >> red[home] >> green[home] >> blue[home];
	}

	memset(cache, -1, sizeof(cache));

	//첫번째 집을 각 색깔별로 초기화
	//0 : red , 1 : green , 2 : blue
	cache[1][0] = red[1];
	cache[1][1] = green[1];
	cache[1][2] = blue[1];

	//두번째 집부터 반복문을 적용하는데, 
	//반복문을 돌 때마다 각 cache[i][color](color: 0~2)에 각 color마다
	//현재 집(i)의 그 색깔로 칠하는 비용 + 이전까지 집들을 칠해온 총 값들 중 다른 색깔 cache[i-1][color]들 중 작은값을 더한다.
	for (int i = 2; i <= N; ++i)
	{
		cache[i][0] = red[i] + min(cache[i - 1][1], cache[i - 1][2]);
		cache[i][1] = green[i] + min(cache[i - 1][0], cache[i - 1][2]);
		cache[i][2] = blue[i] + min(cache[i - 1][0], cache[i - 1][1]);
	}

	//마지막 값들 중 최소값을 출력
	cout << min(cache[N][0], min(cache[N][1], cache[N][2])) << endl;

	return 0;
}
