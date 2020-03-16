#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N;
	int min = 0;
	cin >> N;

	if (N == 1)
	{
		min = 1;
	}
	else
	{
		double t = (N - 1) / 6.0;
		int n = 0;
		//n*(n+1)>=2t ÀÏ ¶§ n
		//min = n+1;
		while (1)
		{
			if (n*(n + 1) >= 2 * t)
			{
				break;
			}
			else
				n++;
		}
		min = n+1;
	}

	cout << min;
	return 0;
}