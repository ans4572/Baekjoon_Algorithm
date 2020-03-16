#include<iostream>

using namespace std;

int main()
{
	int A, B, C;
	int sell;
	cin >> A >> B >> C;
	if (C == B || C < B)
	{
		sell = -1;
	}
	else
	{
		sell = A / (C - B)+1;
	}
	cout << sell;

	return 0;
}