/*
전형적인 분할 정복 문제.
4칸씩 나누면서 나눈 부분의 숫자가 같은지 판별하면서 재귀함수 사용
2차원 배열을 사용할때 x,y 헷갈리지 않게 조심하기!
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
	//기저사례
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