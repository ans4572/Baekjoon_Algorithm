#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Word
{
public:
	string w;
	Word() {}
	Word(string w)
	{
		this->w = w;
	}
	friend bool operator <(Word a, Word b)
	{
		if (a.w.length() < b.w.length())
			return true;
		else if ((a.w.length() == b.w.length()) && (a.w < b.w))
			return true;

		return false;
	}

};

template<typename T>
void Tswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

Word temp[100000];

void merge(vector<Word> &arr, int l, int m, int r)
{
	int first = l;
	int second = m + 1;
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

void mergeSort(vector<Word> &arr, int l, int r)
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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string s;
	vector<Word> vec;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		vec.push_back(Word(s));
	}

	mergeSort(vec, 0, vec.size() - 1);

	for (int i = 0; i < N; ++i)
	{
		if (i == 0)
			cout << vec[i].w << "\n";
		else if(vec[i].w != vec[i-1].w)
			cout << vec[i].w << "\n";
	}

	return 0;
}