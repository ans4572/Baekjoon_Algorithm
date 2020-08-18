#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class point {
public:
	int x, y;

	point() {}

	point(int i, int j) {
		x = i;
		y = j;
	}
};

int N, M, ans = 0;
int dx[4] = { -1,0,+1,0 };
int dy[4] = { 0,+1,0,-1 };
vector<point> candidate;

//범위 안에 있는지 확인하는 함수
bool possible(int x,int y){
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	else
		return false;
}

int change(int a, int b, int c, queue<point> q, vector<vector<int> > map) {
	map[candidate[a].x][candidate[a].y] = 1;
	map[candidate[b].x][candidate[b].y] = 1;
	map[candidate[c].x][candidate[c].y] = 1;

	int new_x, new_y;
	point n;
	while (!q.empty()) {
		n.x = q.front().x;
		n.y = q.front().y;
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			new_x = n.x + dx[i];
			new_y = n.y + dy[i];
			if (possible(new_x, new_y) && map[new_x][new_y] == 0) {
				map[new_x][new_y] = 2;
				q.push(point(new_x, new_y));
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 0)
				count++;
		}
	}

	return count;
}

int main() {
	cin >> N >> M;
	vector<vector<int> > map(N, vector<int>(M));
	queue<point> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				candidate.push_back(point(i, j));
			else if (map[i][j] == 2)
				q.push(point(i, j));
		}
	}

	for (int i = 0; i < candidate.size(); ++i) {
		for (int j = i + 1; j < candidate.size(); ++j) {
			for (int k = j + 1; k < candidate.size(); ++k) {
				int count = change(i, j, k, q, map);
				if (ans < count)
					ans = count;
			}
		}
	}

	cout << ans << endl;

	return 0;
}