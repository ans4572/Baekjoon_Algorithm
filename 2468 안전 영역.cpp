#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class point {
public:
	int x, y;

	point() {}

	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int N, ans = 0;
int dx[4] = { -1,0,+1,0 };
int dy[4] = { 0,+1,0,-1 };

//범위 안에 있는지 확인하는 함수
bool possible(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}

int BFS(int h, vector<vector<int> > map) {
	int count = 0;
	vector<vector<bool> > visit(N, vector<bool>(N,false));
	queue<point> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] > h && visit[i][j] == false) {
				q.push(point(j, i));
				visit[i][j] = true;
			}
			else
				continue;
			
			//q에 하나라도 들어왔다면 BFS 과정 진행
			//x: j , y: i
			while (!q.empty()) {
				for (int k = 0; k < 4; ++k) {
					int nX = q.front().x + dx[k];
					int nY = q.front().y + dy[k];

					if (possible(nX,nY) && map[nY][nX] > h && visit[nY][nX] == false) {
						q.push(point(nX, nY));
						visit[nY][nX] = true;
					}
				}
				q.pop();
			}
			count++;
		}
	}

	return count;
}

int main() {
	cin >> N;

	int maxHeight = 0; 
	vector<vector<int> > map(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (maxHeight < map[i][j])
				maxHeight = map[i][j];
		}
	}

	//가장 높은 높이 전까지 높이별로 BFS 진행
	for (int i = 0; i < maxHeight; ++i) {
		int count = BFS(i, map);
		if (ans < count)
			ans = count;
	}

	cout << ans << endl;

	return 0;
}