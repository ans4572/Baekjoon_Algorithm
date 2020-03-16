#include<iostream>

using namespace std;

int binomial(int n, int k)
{
	//±âÀú »ç·Ê
	if (k == 0 || n == k)
		return 1;

	return (binomial(n - 1, k - 1) % 1000000007 + binomial(n - 1, k) % 1000000007) % 1000000007;
}

int main()
{
	int N, K;
	cin >> N >> K;

	cout << binomial(N, K) << endl;

	return 0;
}