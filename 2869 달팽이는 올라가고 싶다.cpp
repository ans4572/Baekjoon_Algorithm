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
	V-A�� �Ϸ� �ö󰬴� ������ ���� �������� �� �������ٸ� �Ϸ縸 �� �ϸ� �ǰ�
	�� �������� �ʴ´ٸ� ��Ʋ�� �� �ϸ� �ȴ�.
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