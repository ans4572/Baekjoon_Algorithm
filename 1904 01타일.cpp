#include<iostream>

using namespace std;

int mod = 15746; //mod값

int main()
{
	int N;
	cin >> N;

	int a = 2, b = 1; //N이 3이상일때 사용할 변수
	if (N <= 2)
		cout << N << endl;
	else
	{
		for (int i = 3; i <= N; ++i)
		{
			int c = (a + b) % mod; //계산할때마다 미리 mod값으로 나눠준다.
			b = a;
			a = c;
		}
	}

	cout << a << endl;

	return 0;
}