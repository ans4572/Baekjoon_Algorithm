#include<iostream>

using namespace std;

int main()
{
	int arr[8];
	for (int i = 0; i < 8; ++i)
		cin >> arr[i];

	//�������� �Ǻ�
	if (arr[0] == 1)
	{
		bool ascending = true;
		for (int i = 1; i < 8; ++i)
		{
			if (arr[i] < arr[i - 1]) {
				cout << "mixed" << endl;
				ascending = false;
				break;
			}
		}
		if(ascending)
			cout << "ascending" << endl;
	}
	//�������� �Ǻ�
	else if (arr[0] == 8)
	{
		bool descending = true;
		for (int i = 1; i < 8; ++i)
		{
			if (arr[i] > arr[i - 1]) {
				cout << "mixed" << endl;
				descending = false;
				break;
			}
		}
		if(descending)
			cout << "descending" << endl;
	}

	return 0;
}