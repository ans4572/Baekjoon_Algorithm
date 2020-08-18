#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int M, N, K, ans = 0;
vector<int> squareSize;
int dx[4] = { -1,0,+1,0 };
int dy[4] = { 0,+1,0,-1 };

class point {
public:
	int x, y;

	point() {}

	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

//범위 안에 있는지 확인하는 함수
bool possible(int y, int x) {
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	else
		return false;
}

//사각형으로 칠하는 함수
void paint(int a_x, int a_y, int b_x, int b_y, vector<vector<int> > &map) {
	for (int i = a_y; i <= b_y - 1; ++i) {
		for (int j = a_x; j <= b_x - 1; ++j) {
			map[i][j] = 1;
		}
	}

	return;
}

void BFS(int size, queue<point> &q, vector<vector<int> > &map) {
	while (!q.empty()) {
		size++;
		int nx = q.front().x, ny = q.front().y;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (possible(ny + dy[i], nx + dx[i]) && map[ny + dy[i]][nx + dx[i]] == 0) {
				q.push(point(nx + dx[i], ny + dy[i]));
				map[ny + dy[i]][nx + dx[i]] = 1;
			}
		}
	}
	ans++;
	squareSize.push_back(size);

	return;
}

int main() {
	cin >> M >> N >> K;

	vector<vector<int> > map(M, vector<int>(N, 0));
	vector<vector<bool> > visit(M, vector<bool>(N, false));

	//직사각형으로 칠하기
	int a_x, a_y, b_x, b_y;
	for (int i = 0; i < K; ++i) {
		cin >> a_x >> a_y >> b_x >> b_y;
		paint(a_x, a_y, b_x, b_y, map);
	}

	queue<point> q;
	//i: y, j: x
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 0) {
				q.push(point(j, i));
				map[i][j] = 1;
				BFS(0, q, map);
			}
		}
	}

	cout << ans << endl;
	sort(squareSize.begin(), squareSize.end());
	for (int i = 0; i < squareSize.size(); ++i) {
		cout << squareSize[i] << " ";
	}
	cout << endl;

	return 0;
}