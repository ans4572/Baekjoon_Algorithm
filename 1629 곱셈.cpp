/*
�Ϲ� �ŵ����� �Լ��δ� �ð����� Ǯ�� ���ϹǷ� ���� �������� Ǯ�����
���ݾ� �ɰ��� ����ϰ� return�� �� �� ���� �� ���ϴ� ������ %mod�� �������.
*/
#include<iostream>

using namespace std;

long long myPow(long long base, long long exp, long long mod)
{
	//�������
	if (exp == 0)
		return 1;

	long long half = myPow(base, exp / 2, mod);
	if (exp % 2 == 0)
	{
		return ((half % mod) * (half % mod)) % mod;
	}
	else
		return ((base * half % mod) * (half % mod)) % mod;
}

int main()
{
	long long A, B, C;
	cin >> A >> B >> C;

	cout << myPow(A,B,C) << endl;

	return 0;
}