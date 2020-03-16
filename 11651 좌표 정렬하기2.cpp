/*
점 x,y를 동시에 있으므로 class를 활용
Point 클래스 객체 배열을 활용하여 정렬
이 때, n^2 정렬을 하면 시간초과가 나므로 합병정렬을 활용.
*/
#include<iostream>
#include<vector>

using namespace std;

class Point
{
public:
	int x;
	int y;

	Point() {}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	friend bool operator < (const Point f, const Point s)
	{
		if (f.y < s.y)
			return true;
		else if (f.y == s.y && f.x < s.x)
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

Point temp[100000];

void merge(vector<Point> &arr, int l, int m, int r)
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

void mergeSort(vector<Point> &arr, int l, int r)
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

	vector<Point> vec;
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		vec.push_back(Point(x, y));
	}

	mergeSort(vec, 0, vec.size() - 1);

	for (int i = 0; i < N; ++i)
	{
		cout << vec[i].x << " " << vec[i].y << "\n";
	}

	return 0;
}