#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

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

int N;
int dx[4] = { -1,0,+1,0 };
int dy[4] = { 0,+1,0,-1 };

//범위 안에 있는지 확인하는 함수
bool possible(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}

int BFS(vector<vector<char> > map) {
	vector<vector<bool> > visit(N, vector<bool>(N, false));
	int count = 0;
	int nX, nY;
	queue<point> q;

	//i: x, j: y
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visit[i][j] == false) {
				q.push(point(i, j));
				visit[i][j] = true;
			}
			else
				continue;

			while (!q.empty()) {
				for (int k = 0; k < 4; ++k) {
					nX = q.front().x + dx[k];
					nY = q.front().y + dy[k];
					if (possible(nX, nY) && visit[nX][nY] == false && map[i][j] == map[nX][nY]) {
						q.push(point(nX, nY));
						visit[nX][nY] = true;
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

	vector<vector<char> > normalMap(N, vector<char>(N));
	vector<vector<char> > abnormalMap(N, vector<char>(N));

	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < N; ++j) {
			normalMap[i][j] = s[j];
			if (normalMap[i][j] == 'R' || normalMap[i][j] == 'G')
				abnormalMap[i][j] = 'A';
			else
				abnormalMap[i][j] = s[j];
		}
	}

	cout << BFS(normalMap) << " " << BFS(abnormalMap) << endl;

	return 0;
}