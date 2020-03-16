#include<iostream>

using namespace std;

int main()
{
	int A, B, V;
	int location = 0;
	int day = 0;
	int haru;
	cin >> A >> B >> V;
	haru = A - B;
	/*
	V-A가 하루 올라갔다 내려온 수와 나눴을때 딱 나눠진다면 하루만 더 하면 되고
	딱 나눠지지 않는다면 이틀을 더 하면 된다.
	*/
	if ((V - A) % haru == 0) {
		day = (V - A) / haru + 1;
	}
	else
	{
		day = (V - A) / haru + 2;
	}

	cout << day << endl;

	return 0;
}