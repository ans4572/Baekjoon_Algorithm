/*
���� ��(m)�� Ŀ������ �Ϲ� ����������δ� �Ұ���
���� ���������� �Ͽ����ϰ� �־����� m�� ������ ũ�Ƿ�
int�� �ƴ� long long���� �Ͽ����Ѵ�.
���� ���ǿ� %1000�� �ؾ��ϴµ� �� �� �� ��İ����� �� ������ %1000�� �ص� ����� ����.
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