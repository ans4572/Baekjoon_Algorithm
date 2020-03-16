#include<iostream>

using namespace std;

int main()
{
	int a, b;
	int new_a, new_b;
	cin >> a >> b;

	new_a = (a % 10) * 100 + (a % 100 - a % 10) + a / 100;
	new_b = (b % 10) * 100 + (b % 100 - b % 10) + b / 100;

	if (new_a > new_b)
		cout<<new_a;
	else
		cout<<new_b;

	return 0;
}