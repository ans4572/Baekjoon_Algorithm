/*
제곱 수(m)이 커질수록 일반 행렬제곱으로는 불가능
따라서 분할정복을 하여야하고 주어지는 m의 범위가 크므로
int가 아닌 long long으로 하여야한다.
문제 조건에 %1000을 해야하는데 이 때 각 행렬곱셈을 할 때마다 %1000을 해도 결과가 같다.
*/
#include<iostream>
#include<vector>

using namespace std;

class SquareMatrix {
public:
	long long n;
	vector< vector<long long> > matrix;
	
	SquareMatrix(long long n)
	{
		this->n = n;
		for (long long i = 0; i < n; ++i)
		{
			vector<long long> element(n);
			matrix.push_back(element);
		}

		for (long long i = 0; i < n; ++i)
		{
			for (long long j = 0; j < n; ++j)
			{
				matrix[j][i] = 0;
			}
		}
	}

	void PrintMatrix()
	{
		for (long long i = 0; i < n; ++i)
		{
			for (long long j = 0; j < n; ++j)
			{
				cout << matrix[j][i] % 1000<<" ";
			}
			cout << "\n";
		}
	}

	friend SquareMatrix operator *(SquareMatrix A, SquareMatrix B)
	{
		SquareMatrix result(A.n);
		for (long long i = 0; i < A.n; ++i)
		{
			for (long long j = 0; j < B.n; ++j)
			{
				for (long long k = 0; k < A.n; ++k)
				{
					result.matrix[j][i] += A.matrix[k][i] * B.matrix[j][k];
					result.matrix[j][i] %= 1000;
				}
			}
		}

		return result;
	}
};

SquareMatrix Pow(const SquareMatrix &A, long long m)
{
	if (m == 1)
		return A;

	if (m % 2 == 1)
		return Pow(A, m - 1) * A;
	SquareMatrix half = Pow(A, m / 2);
	
	return half * half;
}

int main()
{
	long long N,B;

	cin >> N >> B;

	SquareMatrix A(N);

	for (long long i = 0; i < N; ++i)
	{
		for (long long j = 0; j < N; ++j)
		{
			cin >> A.matrix[j][i];
		}
	}

	SquareMatrix result(N);

	result = Pow(A, B);

	result.PrintMatrix();

	return 0;
}