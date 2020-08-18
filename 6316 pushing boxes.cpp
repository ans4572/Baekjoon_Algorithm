#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 21;  //�̷��� �ִ� ũ��

int R,C;
char maze[MAX][MAX];        //�̷�
bool visitMole[MAX][MAX];   //�δ��� �湮 ǥ��
bool visitBox[MAX][MAX];    //���� �湮 ǥ��

//4����
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

char pushes[4] = { 'E','W','S','N' };
char walkes[4] = { 'e','w','s','n' };

string path;               //�ּ� �� ���� (=ans)

struct NODE {
	int br, bc;     //�ڽ� ��ġ
	int mr, mc;     //�δ��� ��ġ
	string ans;     //������ ����
};

//������ �� �ִ� ������ Ȯ���ϴ� �Լ�
bool inMaze(int r, int c) {
	return (r >= 1 && r <= R && c >= 1 && c <= C);
}

//�ι�° BFS
//���� ���� maze[sr][sc]���� �� ���� maze[er][ec]�� �� �� �ִ��� ������ �Ǻ�
bool BFS2(int sr, int sc, int er, int ec, int br, int bc, string& ans) {
	memset(visitMole, false, sizeof(visitMole));     //�δ��� �湮 ǥ�� �ʱ�ȭ

	queue<NODE> q;    
	NODE node, nextNode;       //node: q���� ���� �տ� �ִ� ���, nextNode: ���� ���
	node.mr = sr; node.mc = sc; node.ans = ""; 
	q.push(node);
	visitMole[br][bc] = true;  

	//q�� �������� �ݺ�
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node.mr == er && node.mc == ec) {
			ans = node.ans;
			return true;
		}

		//�̹� �湮�� ���̶�� continue
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

//ù��° BFS
bool BFS1(int sr, int sc, int br, int bc) {
	memset(visitBox, false, sizeof(visitBox));    //�ڽ� �湮 �ʱ�ȭ
	queue<NODE> q;
	NODE node, nextNode;   
	node.mr = sr; node.mc = sc; node.br = br; node.bc = bc; node.ans = "";  //�δ����� ���� ��ġ�� ���� ó�� ��ġ�� node �Ҵ�
	q.push(node);

	//q�� �������� ����
	while (!q.empty()) {
		node = q.front();
		q.pop();

		if (visitBox[node.br][node.bc]) continue;  //�̹� �湮�� ���̶�� continue

		visitBox[node.br][node.bc] = true;         //�湮 ǥ��

		//���� ��������� ���� path�� �����ϰ� true��ȯ�ϸ鼭 �Լ� ����
		if (maze[node.br][node.bc] == 'T') {
			path = node.ans; return true;
		}

		//4���� Ž��
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
	int sr, sc;     //���� ���� ����
	int br, bc;     //�ڽ� ��ġ ����
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