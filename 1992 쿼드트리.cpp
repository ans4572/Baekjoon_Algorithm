/*
�������� ���� ���� ����.
4ĭ�� �����鼭 ���� �κ��� ���ڰ� ������ �Ǻ��ϸ鼭 ����Լ� ���
2���� �迭�� ����Ҷ� x,y �򰥸��� �ʰ� �����ϱ�!
*/
#include<iostream>
#include<vector>
#include<string>

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

void compression(vector< vector<char> > &vec,Point p1,Point p2, string &result)
{
	bool same = true;
	char f = vec[p1.x][p1.y];
	for (int i = p1.y; i < p2.y; ++i)
	{
		for (int j = p1.x; j < p2.x; ++j)
		{
			if (f != vec[j][i])
			{
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
		if (f == '1')
			result += "1";
		else
			result += "0";
		return;
	}
	
	result += "(";
	compression(vec, Point(p1.x, p1.y), Point((p2.x + p1.x) / 2, (p2.y + p1.y) / 2), result);
	compression(vec, Point((p2.x + p1.x) / 2, p1.y), Point(p2.x, (p2.y + p1.y) / 2), result);
	compression(vec, Point(p1.x, (p2.y + p1.y) / 2), Point((p2.x + p1.x) / 2, p2.y), result);
	compression(vec, Point((p2.x + p1.x) / 2, (p2.y + p1.y) / 2), Point(p2.x, p2.y), result);
	
	result += ")";

	return;
}

int main()
{
	int N;
	cin >> N;

	string result = "\0";
	vector< vector<char> > vec;

	for (int i = 0; i < N; ++i)
	{
		vector<char> element(N);
		vec.push_back(element);
	}
	char n;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
		{
			cin >> n;
			vec[j][i] = n;
		}
	}

	compression(vec, Point(0, 0), Point(N, N), result);

	cout << result << endl;

	return 0;
}