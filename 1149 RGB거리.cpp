#include<iostream>
#include<cstring> //memset�� ����ϱ� ���� ���
#include<algorithm> //min�� ����ϱ� ���� ���

using namespace std;

int N;
int red[1001], green[1001], blue[1001]; //���� �迭
int cache[1001][3]; //�޸������̼��� ���� �迭

int main()
{
	cin >> N;

	for (int home = 1; home <= N; ++home)
	{
		cin >> red[home] >> green[home] >> blue[home];
	}

	memset(cache, -1, sizeof(cache));

	//ù��° ���� �� ���򺰷� �ʱ�ȭ
	//0 : red , 1 : green , 2 : blue
	cache[1][0] = red[1];
	cache[1][1] = green[1];
	cache[1][2] = blue[1];

	//�ι�° ������ �ݺ����� �����ϴµ�, 
	//�ݺ����� �� ������ �� cache[i][color](color: 0~2)�� �� color����
	//���� ��(i)�� �� ����� ĥ�ϴ� ��� + �������� ������ ĥ�ؿ� �� ���� �� �ٸ� ���� cache[i-1][color]�� �� �������� ���Ѵ�.
	for (int i = 2; i <= N; ++i)
	{
		cache[i][0] = red[i] + min(cache[i - 1][1], cache[i - 1][2]);
		cache[i][1] = green[i] + min(cache[i - 1][0], cache[i - 1][2]);
		cache[i][2] = blue[i] + min(cache[i - 1][0], cache[i - 1][1]);
	}

	//������ ���� �� �ּҰ��� ���
	cout << min(cache[N][0], min(cache[N][1], cache[N][2])) << endl;

	return 0;
}
