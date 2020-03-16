#include<iostream>
#include<string>

using namespace std;

template<typename T>
void Tswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void insertSort(string &num)
{
	for (int i = 0; i < num.length(); ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (num[j - 1] > num[j])
				Tswap(num[j - 1], num[j]);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	string num = to_string(N);
	insertSort(num);
	for (int i = num.length() - 1; i >= 0; --i)
		cout << num[i];
	cout << endl;
}