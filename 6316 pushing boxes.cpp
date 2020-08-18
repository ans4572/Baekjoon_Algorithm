#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 21;  //미로의 최대 크기

int R,C;
char maze[MAX][MAX];        //미로
bool visitMole[MAX][MAX];   //두더지 방문 표시
bool visitBox[MAX][MAX];    //상자 방문 표시

//4방향
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

char pushes[4] = { 'E','W','S','N' };
char walkes[4] = { 'e','w','s','n' };

string path;               //최소 길 저장 (=ans)

struct NODE {
	int br, bc;     //박스 위치
	int mr, mc;     //두더지 위치
	string ans;     //움직임 순서
};

//움직일 수 있는 곳인지 확인하는 함수
bool inMaze(int r, int c) {
	return (r >= 1 && r <= R && c >= 1 && c <= C);
}

//두번째 BFS
//시작 지점 maze[sr][sc]에서 끝 지점 maze[er][ec]로 갈 수 있는지 없는지 판별
bool BFS2(int sr, int sc, int er, int ec, int br, int bc, string& ans) {
	memset(visitMole, false, sizeof(visitMole));     //두더지 방문 표시 초기화

	queue<NODE> q;    
	NODE node, nextNode;       //node: q에서 가장 앞에 있는 노드, nextNode: 다음 노드
	node.mr = sr; node.mc = sc; node.ans = ""; 
	q.push(node);
	visitMole[br][bc] = true;  

	//q가 빌때까지 반복
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node.mr == er && node.mc == ec) {
			ans = node.ans;
			return true;
		}

		//이미 방문한 곳이라면 continue
		if (visitMole[node.mr][node.mc]) continue;

		visitMole[node.mr][node.mc] = true;
		for (int i = 0; i < 4; ++i) {
			int nr = node.mr + dr[i];
			int nc = node.mc + dc[i];
			if (inMaze(nr, nc) && !visitMole[nr][nc] && maze[nr][nc] != '#') {
				nextNode.mr = nr; nextNode.mc = nc; nextNode.ans = node.ans + walkes[i];
				q.push(nextNode);
			}
		}
	}

	return false;
}

//첫번째 BFS
bool BFS1(int sr, int sc, int br, int bc) {
	memset(visitBox, false, sizeof(visitBox));    //박스 방문 초기화
	queue<NODE> q;
	NODE node, nextNode;   
	node.mr = sr; node.mc = sc; node.br = br; node.bc = bc; node.ans = "";  //두더지의 시작 위치와 상자 처음 위치로 node 할당
	q.push(node);

	//q가 빌때까지 진행
	while (!q.empty()) {
		node = q.front();
		q.pop();

		if (visitBox[node.br][node.bc]) continue;  //이미 방문한 곳이라면 continue

		visitBox[node.br][node.bc] = true;         //방문 표시

		//만약 목적지라면 길을 path에 저장하고 true반환하면서 함수 종료
		if (maze[node.br][node.bc] == 'T') {
			path = node.ans; return true;
		}

		//4방향 탐색
		for (int i = 0; i < 4; ++i) {
			int nextR = node.br + dr[i];
			int nextC = node.bc + dc[i];

			int backR = node.br - dr[i];
			int backC = node.bc - dc[i];

			string ans = "";

			if (inMaze(backR, backC) && inMaze(nextR, nextC)
				&& maze[nextR][nextC] != '#' && maze[backR][backC] != '#'
				&& !visitBox[nextR][nextC]) {
				if (BFS2(node.mr, node.mc, backR, backC, node.br, node.bc, ans)) {
					nextNode.mr = node.br; nextNode.mc = node.bc;
					nextNode.br = nextR; nextNode.bc = nextC;
					nextNode.ans = node.ans + ans + pushes[i];
					q.push(nextNode);
				}
			}
		}
	}
	return false;
}

int main() {
	int sr, sc;     //시작 지점 저장
	int br, bc;     //박스 위치 저장
	int cases = 1;

	while (true) {
		cin >> R >> C;

		if (R == 0 && C == 0) break;

		for (int r = 1; r <= R; ++r) {
			for (int c = 1; c <= C; ++c) {
				cin >> maze[r][c];

				if (maze[r][c] == 'S') { 
					sr = r;
					sc = c; 
				}
				if (maze[r][c] == 'B') { 
					br = r; 
					bc = c; 
				}
			}
		}

		path = "";

		bool possible = BFS1(sr, sc, br, bc);

		cout << "Maze #" << cases << endl;
		if (possible) cout << path << endl;
		else cout << "Impossible." << endl;

		cases++;
		cout << endl;
	}

	return 0;
}