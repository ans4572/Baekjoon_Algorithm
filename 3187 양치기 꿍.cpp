#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class point {
public:
	int i, j;

	point() {}

	point(int i, int j) {
		this->i = i;
		this->j = j;
	}
};

int R, C;
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,-1,0,1 };
int vCount = 0, kCount = 0;

bool possible(int i, int j) {
	if (i >= 0 && i < R && j >= 0 && j < C)
		return true;
	else
		return false;
}

void BFS(queue<point> q, vector<vector<char> > map, vector<vector<bool> > &visit) {
	int tempV = 0, tempK = 0;

	//처음 q에 있는 것이 양이거나 늑대인지 확인.
	if (map[q.front().i][q.front().j] == 'v') 
		tempV += 1;
	else if (map[q.front().i][q.front().j] == 'k') 
		tempK += 1;

	while (!q.empty()) {
		int i, j;

		for (int t = 0; t < 4; ++t) {
			i = q.front().i + di[t];
			j = q.front().j + dj[t];
			if (possible(i, j) && visit[i][j] == false && map[i][j] != '#')
			{
				q.push(point(i, j));
				visit[i][j] = true;
				if (map[i][j] == 'v') {
					tempV++;
				}
				else if (map[i][j] == 'k') {
					tempK++;
				}
			}
		}
		q.pop();
	}

	//양이 더 많은 경우 양의 수만 더해준다.
	if (tempV < tempK) {
		kCount += tempK;
	}
	//그 외 늑대의 수만 더해준다.
	else {
		vCount += tempV;
	}
}

int main()
{
	cin >> R >> C;

	vector<vector<char> > map(R, vector<char>(C));
	vector<vector<bool> > visit(R, vector<bool>(C, false));

	//#: 울타리, v: 늑대, k: 양
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			queue<point> q;
			if (map[i][j] != '#' && visit[i][j] == false) {
				visit[i][j] = true;
				q.push(point(i, j));
				BFS(q, map, visit);
			}
		}
	}

	cout << kCount << " " << vCount << endl;

	return 0;
}