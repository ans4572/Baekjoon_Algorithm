#include<iostream>
#include<cstring> //memset을 위한 헤더
#include<algorithm> //max를 위한 헤더

using namespace std;

int triangle[501][501] = { 0 }; //입력받는 삼각형들의 값 저장 배열
int cache[501][501]; //메모이제이션을 위한 배열, 꼭대기부터 내려오면서 최대값 저장

int main()
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> triangle[i][j];

	cache[1][1] = triangle[1][1];

	//삼각형 맨 위는 초기화 해줬으니 그 밑부터 시작
	//양 끝은 위에서 위에서 내려올 때 받을 수 있는 최대 경로는 하나밖에 없으므로 따로 계산해주고
	//양 끝이 아닌 삼각형들은 위에서 내려올 때 최대가 되는 경로 
	//두 개 중 더 큰값에서 내려오는 경로를 택하면 된다.
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == 1)
				cache[i][j] = triangle[i][j] + cache[i - 1][j];
			else if (j == i)
				cache[i][j] = triangle[i][j] + cache[i - 1][j - 1];
			else
			{
				cache[i][j] = triangle[i][j] + max(cache[i - 1][j - 1], cache[i - 1][j]);
			}
		}
	}

	//cache배열에서 맨 아래층들 중 최대값이 구하고자하는 값이 된다. 
	int max = cache[n][1];
	for (int t = 1; t <= n; ++t)
	{
		if (max < cache[n][t])
			max = cache[n][t];
	}

	cout << max << endl;

	return 0;
}