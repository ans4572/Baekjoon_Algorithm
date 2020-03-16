#include<iostream>

using namespace std;

#define PI 3.14159265358979323846

int main()
{
	int radius;
	cin >> radius;

	cout << fixed;
	cout.precision(6);

	cout << radius * radius*PI << endl;
	cout << (double)(2 * radius * radius) << endl;

	return 0;
}