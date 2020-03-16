#include<iostream>
#include<vector>

using namespace std;

int temp[1000000];

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void merge(vector<int> &arr, int l,int m, int r)
{
	int first = l;
	int second = m+1;
	int k = 0;

	while (first <= m && second <= r)
	{
		if (arr[first] < arr[second])
			temp[k] = arr[first++];
		else
			temp[k] = arr[second++];
		k++;
	}

	while (first <= m)
	{
		temp[k] = arr[first++];
		k++;
	}

	while (second <= l)
	{
		temp[k] = arr[second++];
		k++;
	}
	k--;

	while (k >= 0) 
	{
		arr[l + k] = temp[k];
		k--;
	}
}

void mergeSort(vector<int> &arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
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

	mergeSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << "\n";

	return 0;
}