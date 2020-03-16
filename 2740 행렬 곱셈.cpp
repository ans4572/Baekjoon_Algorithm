#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M, K;

	cin >> N >> M;

	int A[100][100] = {};
	int B[100][100] = {};
	int C[100][100] = {};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> A[j][i];
		}

	}

	cin >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			cin >> B[j][i];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			for (int k = 0; k < M; ++k)
				C[j][i] += A[k][i] * B[j][k];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
			cout << C[j][i] <<" ";
		cout << endl;
	}

	return 0;
}