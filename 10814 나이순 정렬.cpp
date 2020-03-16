#include<iostream>
#include<vector>
#include<string>

using namespace std;

class member
{
public:
	int age;
	string name;
	member() {};
	member(int age, string name)
	{
		this->age = age;
		this->name = name;
	}

	friend bool operator <(member a, member b)
	{
		if (a.age < b.age)
			return true;

		return false;
	}
};

template<typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

vector<member> temp(100000);

void merge(vector<member> &vec, int l, int m, int r)
{
	int first = l;
	int second = m + 1;
	int k = 0;

	while (first <= m && second <= r)
	{
		if (vec[first] < vec[second] || vec[first].age == vec[second].age)
		{
			temp[k++] = vec[first++];
		}
		else
		{
			temp[k++] = vec[second++];
		}
	}

	while (first <= m)
		temp[k++] = vec[first++];

	while (second <= r)
		temp[k++] = vec[second++];

	k--;

	while (k >= 0)
	{
		vec[l + k] = temp[k];
		k--;
	}
}


void mergeSort(vector<member> &vec,int l,int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(vec, l, m);
		mergeSort(vec, m+1, r);
		merge(vec, l, m, r);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<member> vec;
	int age;
	string name;
	for (int i = 0; i < N; ++i)
	{
		cin >> age >> name;
		vec.push_back(member(age, name));
	}

	mergeSort(vec,0,vec.size()-1);

	for (int i = 0; i < N; ++i)
	{
		cout << vec[i].age << " " << vec[i].name << "\n";
	}

	return 0;
}