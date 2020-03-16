#include<iostream>
#include<cstring>

using namespace std;

long long cache[91]; //�޸������̼��� ���� �迭

//����Լ��� �̿��� �Ǻ���ġ �Լ�
long long fibo(long long n)
{
	//�������
	if (n <= 1)
		return n;
	long long& ret = cache[n]; //������ ���� ����
	//���� �̹� ����Ͽ��ٸ� �ٷ� ����
	if (ret != -1)
		return ret;
	//�ƴ϶�� ��� �� cache�迭�� ����
	else
		return ret = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	long long n;
	cin >> n;
	memset(cache, -1, sizeof(cache)); //cache�迭�� -1�� �ʱ�ȭ

	cout << fibo(n) << endl;

	return 0;
}