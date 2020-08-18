#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int HEIGHT = 12, WIDTH = 6;

int ans = 0;
char board[HEIGHT][WIDTH];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[HEIGHT][WIDTH];  //방문 표시

//범위 내 존재 여부 확인 함수
bool possible(int x, int y) {
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		return true;
	else
		return false;
}

//x,y 기준점으로 BFS활용하여 상하좌우 같은 색깔 뿌요를 찾은 후 반환
vector<pair<int, int> > nearPuyo(char color, int y, int x) {
	vector<pair<int, int> > v;
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	int tx, ty;


	while (!q.empty()) {
		v.push_back(q.front());
		ty = q.front().first;
		tx = q.front().second;
		visit[ty][tx] = true;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (possible(tx + dx[i], ty + dy[i]) && board[ty + dy[i]][tx + dx[i]] == color && visit[ty + dy[i]][tx + dx[i]] == false) {
				q.push(make_pair(ty + dy[i], tx + dx[i]));
			}	
		}
	}

	return v;
}

//제거 가능한 뿌요 제거하는 함수
void removePuyo(vector<pair<int, int> > v) {
	for (int i = 0; i < v.size(); ++i) {
		board[v[i].first][v[i].second] = '.';
	}
}

//뿌요 재배치
void relocationPuyo() {
	for (int i = 0; i < WIDTH; ++i) {
		vector<char> re;
		//세로 줄에서 제거되지 않은 뿌요들 찾기
		for (int j = HEIGHT - 1; j >= 0; --j) {
			if (board[j][i] != '.') {
				re.push_back(board[j][i]);
				board[j][i] = '.';
			}
		}

		for (int j = 1; j <= re.size(); ++j) {
			board[HEIGHT - j][i] = re[j - 1];
		}
	}
}

void DFS() {
	bool end = true;
	memset(visit, false, sizeof(visit));  //방문 표시 초기화

	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (board[i][j] != '.' && visit[i][j] == false) {
				vector<pair<int, int> > v = nearPuyo(board[i][j], i, j);
				//같은 색 뿌요가 4개 이상인 경우
				if (v.size() >= 4) {
					end = false;
					removePuyo(v);
				}
			}
		}
	}

	relocationPuyo();

	if (end == false) {
		ans++;
		DFS();
	}

	return;
}

int main() {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			cin >> board[i][j];
		}
	}

	DFS();

	cout << ans << endl;

	return 0;
}