#include<iostream>
#include<cstring>   //memset�� ���� ���
#include<algorithm> //min�� ���� ���

using namespace std;

int cache[1000001];

int main()
{
	int N;
	cin >> N;

	memset(cache, -1, sizeof(cache));

	//1,2,3�� Ư�� ���̽��� ���� �ʱ�ȭ
	cache[1] = 0;
	cache[2] = cache[3] = 1;

	//4���� �ݺ����� ���鼭 ���� ������ ���� �ϴ� Ƚ���� �����Ѵ�.
	for (int i = 4; i <= N; ++i)
	{
		//3�� 2�� �� �� ���� �� ���� ��
		if (i % 3 == 0 && i % 2 == 0)
			cache[i] = min(cache[i / 3], min(cache[i / 2], cache[i - 1])) + 1;
		//3���� ���� �� ���� ��
		else if (i % 3 == 0)
			cache[i] = min(cache[i / 3], cache[i - 1]) + 1;
		//2�� ���� �� ���� ��
		else if (i % 2 == 0)
			cache[i] = min(cache[i / 2], cache[i - 1]) + 1;
		//-1�ۿ� �� �� ���� ��
		else
			cache[i] = cache[i - 1] + 1;
	}

	cout << cache[N] << endl;

	return 0;
}