#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Matrix {
public:
	int mat[2][2];

	Matrix() {
		mat[0][0] = 1;
		mat[0][1] = 1;
		mat[1][0] = 1;
		mat[1][1] = 0;
	}

	friend Matrix operator *(Matrix A, Matrix B)
	{
		Matrix result = Matrix();
		result.mat[0][0] = (A.mat[0][0] * B.mat[0][0] % 1000000000 + A.mat[0][1] * B.mat[1][0] % 1000000000) % 1000000000;
		result.mat[0][1] = (A.mat[0][0] * B.mat[0][1] % 1000000000 + A.mat[0][1] * B.mat[1][1] % 1000000000) % 1000000000;
		result.mat[1][0] = (A.mat[1][0] * B.mat[0][0] % 1000000000 + A.mat[1][1] * B.mat[1][0] % 1000000000) % 1000000000;
		result.mat[1][1] = (A.mat[1][0] * B.mat[0][1] % 1000000000 + A.mat[1][1] * B.mat[1][1] % 1000000000) % 1000000000;

		return result;
	}
};

Matrix Pow(const Matrix &A, double m)
{
	if (m == 1)
		return A;

	if ((int)m % 2 == 1)
		return Pow(A, m - 1) * A;
	else {
		Matrix half = Pow(A, m / 2);
		return half * half;
	}
}

void res(int t[2][2], Matrix tmp) {
	t[0][0] = tmp.mat[0][0];
	t[0][1] = tmp.mat[0][1];
	t[1][0] = tmp.mat[1][0];
	t[1][1] = tmp.mat[1][1];
}

int main() {
	double a, b;
	cin >> a >> b;

	//ans = f(b+2) - f(a+1)
	//행렬을 활용하여 빠르게 구할 수 있다.
	int temp1[2][2], temp2[2][2];
	int ans;
	Matrix tmp1 = Matrix();
	Matrix tmp2 = Matrix();

	res(temp1, Pow(tmp1, b));
	res(temp2, Pow(tmp2, a - 1));

	ans = (temp1[0][0] + temp1[0][1]) - (temp2[0][0] + temp2[0][1]);

	cout << ans << endl;

	return 0;
}