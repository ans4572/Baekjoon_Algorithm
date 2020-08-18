#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

class Point {
public:
	int x, y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int N;
int dx[4] = { -1,0,+1,0 };
int dy[4] = { 0,+1,0,-1 };

//범위 안에 드는지 확인하는 함수
bool isPossible(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	else
		return false;
}

int main() {
	cin >> N;
	vector<vector<int> > map(N, vector<int>(N));
	vector<vector<bool> > visit(N, vector<bool>(N, false));
	string s;

	//입력에 이어져있는 숫자들이므로 문자열로 받아서 쪼개서 map에 넣기
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < N; ++j) {
			map[i][j] = s[j] - '0';
		}
	}

	queue<Point> q;
	vector<int> count;
	int index = -1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visit[i][j] == false && map[i][j] == 1) {
				visit[i][j] = true;
				q.push(Point(i,j));
				count.push_back(0);
				index++;
			}

			while (!q.empty()) {
				count[index]++;
				for (int i = 0; i < 4; ++i) {
					int nX = q.front().x + dx[i];
					int nY = q.front().y + dy[i];
					if (isPossible(nX, nY) && visit[nX][nY] == false && map[nX][nY] == 1) {
						q.push(Point(nX, nY));
						visit[nX][nY] = true;
					}
				}
				q.pop();
			}
		}
	}
	
	//정렬
	sort(count.begin(), count.end());

	cout << count.size() << endl;
	for (int i = 0; i < count.size(); ++i) {
		cout << count[i] << endl;
	}

	return 0;
}