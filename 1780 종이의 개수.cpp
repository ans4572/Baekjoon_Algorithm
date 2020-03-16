/*
�������� ���� ���� ����.
9ĭ�� �����鼭 ���� �κ��� ���ڰ� ������ �Ǻ��ϸ鼭 ����Լ� ���
2���� �迭�� ����Ҷ� x,y �򰥸��� �ʰ� �����ϱ�!
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

void countPaper(vector< vector<int> > &vec, Point p1, Point p2, int &minusOneCount, int &zeroCount,int &oneCount)
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
	//�������
	if (same == true)
	{
		if (f == -1)
			minusOneCount++;
		else if (f == 0)
			zeroCount++;
		else
			oneCount++;
		return;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			countPaper(vec, Point(p1.x + ((p2.x - p1.x) / 3)*j, (p1.y + ((p2.y - p1.y) / 3)*i)),
				Point(p1.x + ((p2.x - p1.x) / 3)*(j + 1), (p1.y + ((p2.y - p1.y) / 3)*(i + 1))),
				minusOneCount, zeroCount, oneCount);
		}
	}

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
	int minusOneCount = 0, zeroCount = 0, oneCount = 0;
	countPaper(vec, Point(0, 0), Point(N, N), minusOneCount, zeroCount, oneCount);

	cout << minusOneCount << "\n" << zeroCount << "\n" << oneCount << "\n";

	return 0;
}