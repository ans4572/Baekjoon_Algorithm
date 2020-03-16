#include<iostream>
#include<cstring> //memset�� ���� ���
#include<algorithm> //max�� ���� ���

using namespace std;

int stairs[301] = { 0 };
int cache[301]; //�޸������̼��� ���� �迭

int main()
{
	int N;
	cin >> N;
	
	memset(cache, -1, sizeof(cache));

	for (int i = 1; i <= N; ++i)
		cin >> stairs[i];

	//����° ��ܱ����� Ư�����̽��̹Ƿ� �̸� �ʱ�ȭ���ش�
	cache[1] = stairs[1];
	cache[2] = max(stairs[1] + stairs[2], stairs[2]);
	cache[3] = max(stairs[1], stairs[2])+ stairs[3];

	for (int i = 4; i <= N; ++i)
		cache[i] = max(cache[i - 2], cache[i - 3] + stairs[i - 1]) + stairs[i];
	
	cout << cache[N] << endl;

	return 0;
}