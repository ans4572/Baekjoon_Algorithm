#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void insertSort(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	
	vector<int> arr;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		arr.push_back(n);
	}

	insertSort(arr);

	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << endl;

	return 0;
}