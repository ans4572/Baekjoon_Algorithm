#include<iostream>
#include<cstring>    //memset�� ���� ���
#include<algorithm>  //max�� ���� ���

using namespace std;

int wine[10001];
int cache[10001];
int n;

int main()
{
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for (int i = 1; i <= n; ++i)
		cin >> wine[i];

	//0~2�ܱ����� Ư�� ���̽��� ���� �ʱ�ȭ
	cache[0] = 0;
	cache[1] = wine[1];
	cache[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; ++i)
		cache[i] = max(cache[i - 3] + wine[i - 1] + wine[i], max(cache[i - 2] + wine[i], cache[i - 1]));

	cout << cache[n] << endl;

	return 0;
}