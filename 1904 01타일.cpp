#include<iostream>

using namespace std;

int const MOD = 15746; //mod°ª
int dy[1000001];

int main()
{
	int N;
	cin >> N;

	dy[1] = 1;
	dy[2] = 2;

	for (int i = 3; i <= N; ++i) {
		dy[i] = (dy[i - 2] + dy[i - 1]) % MOD;
	}

	cout << dy[N] % MOD << endl;

	return 0;
}