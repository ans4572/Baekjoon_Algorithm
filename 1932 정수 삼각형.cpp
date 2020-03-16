#include<iostream>
#include<cstring> //memset�� ���� ���
#include<algorithm> //max�� ���� ���

using namespace std;

int triangle[501][501] = { 0 }; //�Է¹޴� �ﰢ������ �� ���� �迭
int cache[501][501]; //�޸������̼��� ���� �迭, �������� �������鼭 �ִ밪 ����

int main()
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> triangle[i][j];

	cache[1][1] = triangle[1][1];

	//�ﰢ�� �� ���� �ʱ�ȭ �������� �� �غ��� ����
	//�� ���� ������ ������ ������ �� ���� �� �ִ� �ִ� ��δ� �ϳ��ۿ� �����Ƿ� ���� ������ְ�
	//�� ���� �ƴ� �ﰢ������ ������ ������ �� �ִ밡 �Ǵ� ��� 
	//�� �� �� �� ū������ �������� ��θ� ���ϸ� �ȴ�.
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

	//cache�迭���� �� �Ʒ����� �� �ִ밪�� ���ϰ����ϴ� ���� �ȴ�. 
	int max = cache[n][1];
	for (int t = 1; t <= n; ++t)
	{
		if (max < cache[n][t])
			max = cache[n][t];
	}

	cout << max << endl;

	return 0;
}