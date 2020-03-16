#include<iostream>
#include<cstring>

using namespace std;

long long cache[101][10]; //ù��°�� �ڸ���, �ι�°�� �� �ڸ������� ���� �� �ִ� ����
long long mod = 1000000000;

int main()
{
	int N;
	cin >> N;

	memset(cache, -1, sizeof(cache));

	//ù��°�� Ư�����̽��̹Ƿ� ���� �ʱ�ȭ
	cache[1][0] = 0;
	for (int i = 1; i <= 9; ++i)
		cache[1][i] = 1;

	//�ι�°���ʹ� N���� �ݺ����� ���鼭 �� �ڸ����� ���� �� �ִ� ���� �����Ͽ� ���
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			//i �ڸ������� 0�� ���� �� �ִ� ������ i-1 �ڸ������� 1�� ���� �� �ִ� ������ ����.
			if (j == 0)
				cache[i][j] = cache[i - 1][j + 1];
			//i �ڸ������� 9�� ���� �� �ִ� ������ i-1 �ڸ������� 8�� ���� �� �ִ� ������ ����.
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