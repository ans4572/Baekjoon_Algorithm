#include<iostream>

using namespace std;

int mod = 15746; //mod��

int main()
{
	int N;
	cin >> N;

	int a = 2, b = 1; //N�� 3�̻��϶� ����� ����
	if (N <= 2)
		cout << N << endl;
	else
	{
		for (int i = 3; i <= N; ++i)
		{
			int c = (a + b) % mod; //����Ҷ����� �̸� mod������ �����ش�.
			b = a;
			a = c;
		}
	}

	cout << a << endl;

	return 0;
}