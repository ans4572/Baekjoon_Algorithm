#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int R, C;

class shark {
public:
	int r, c;
	int speed;
	int direction;
	int size;
	bool exist;

	shark() {}

	shark(int r, int c, int s, int d, int z) {
		this->r = r;
		this->c = c;
		direction = d;
		size = z;
		exist = true;
		//상어가 이동할 수 있는 곳은 한계가 있으므로 그 이상의 속도는 무의미하다.
		//따라서 속도를 줄여야하는데, (R-1)*2를 하면 다시 제자리로 돌아온다.
		if (d == 1 || d == 2) {
			speed = s % ((R - 1) * 2);
		}
		else {
			speed = s % ((C - 1) * 2);
		}
	}

	void change() {
		int t = 0;
		while (t < speed) {
			if (direction == 1) {
				if (r == 1) {
					direction = 2;
					r = 2;
				}
				else
					r--;
			}
			else if (direction == 2) {
				if (r == R) {
					direction = 1;
					r = R - 1;
				}
				else
					r++;
			}
			else if (direction == 3) {
				if (c == C) {
					direction = 4;
					c = C - 1;
				}
				else
					c++;
			}
			else {
				if (c == 1) {
					direction = 3;
					c = 2;
				}
				else
					c--;
			}
			t++;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);

	int M;
	cin >> R >> C >> M;
	vector<shark> sharks;
	int board[101][101];  //상어가 있다면 해당 상어 번호(0~M-1), 없다면 -1
	memset(board, -1, sizeof(board));

	int r, c, s, d, z;
	for (int i = 0; i < M; ++i) {
		cin >> r >> c >> s >> d >> z;
		sharks.push_back(shark(r, c, s, d, z));
		board[r][c] = i;
	}

	int sum = 0; //잡은 상어들의 크기 합

	for (int i = 1; i <= C; ++i) {
		for (int j = 1; j <= R; ++j) {
			//j열에 상어가 존재하는 경우
			if (board[j][i] != -1) {
				sum += sharks[board[j][i]].size;

				sharks[board[j][i]].exist = false;
				board[i][j] = -1;
				break;
			}
		}

		memset(board, -1, sizeof(board));
		//상어들 위치 변화 및 board에 이미 존재하는지 확인
		for (int s = 0; s < sharks.size(); ++s) {
			if (sharks[s].exist == false)
				continue;

			sharks[s].change();

			if (board[sharks[s].r][sharks[s].c] == -1)
				board[sharks[s].r][sharks[s].c] = s;
			else {
				//이미 존재하던거보다 새로운 상어가 더 크다면 
				//존재 하던 상어는 살아있지않는 상태로 변경하고
				//해당 board에 새로운 상어의 번호로 넣는다.
				if (sharks[board[sharks[s].r][sharks[s].c]].size < sharks[s].size) {
					sharks[board[sharks[s].r][sharks[s].c]].exist = false;
					board[sharks[s].r][sharks[s].c] = s;
				}
				//새로운 상어가 더 작다면 새로운 상어는 살아있지않는 상태로 변경
				else {
					sharks[s].exist = false;
				}
			}
		}
	}

	cout << sum << endl;

	return 0;
}