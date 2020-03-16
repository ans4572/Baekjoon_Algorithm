/*
전형적인 분할 정복 문제.
4칸씩 나누면서 나눈 부분의 색깔이 같은지 판별하면서 재귀함수 사용
2차원 배열을 사용할때 x,y 헷갈리지 않게 조심하기!
*/
#include<iostream>
#include<vector>

using namespace std;

class Point {
public:
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void countPaper(vector< vector<int> > &vec, Point p1, Point p2, int &wCount, int &bCount)
{
	bool same = true;
	int f = vec[p1.x][p1.y];
	for (int i = p1.y; i < p2.y; ++i)
	{
		for (int j = p1.x; j < p2.x; ++j)
		{
			if (f != vec[j][i]) {
				same = false;
				break;
			}
		}
		if (same == false)
			break;
	}
	//기저사례
	if (same == true)
	{
		if (f == 0)
			wCount++;
		else
			bCount++;
		return;
	}

	countPaper(vec, Point(p1.x, p1.y), Point((p2.x + p1.x) / 2, (p2.y + p1.y) / 2), wCount, bCount);
	countPaper(vec, Point((p2.x + p1.x) / 2, p1.y), Point(p2.x, (p2.y + p1.y) / 2), wCount, bCount);
	countPaper(vec, Point(p1.x, (p2.y + p1.y) / 2), Point((p2.x + p1.x) / 2, p2.y), wCount, bCount);
	countPaper(vec, Point((p2.x + p1.x) / 2, (p2.y + p1.y) / 2), Point(p2.x, p2.y), wCount, bCount);

	return;
}

int main()
{
	int N;
	cin >> N;

	vector< vector<int> > vec;

	for (int i = 0; i < N; ++i)
	{
		vector<int>	element(N);
		vec.push_back(element);
	}
	int n;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
		{
			cin >> n;
			vec[j][i] = n;
		}
	}
	int wCount = 0, bCount = 0;
	countPaper(vec, Point(0, 0), Point(N, N), wCount, bCount);

	cout << wCount << "\n" << bCount << "\n";

	return 0;
}