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
		//�� �̵��� �� �ִ� ���� �Ѱ谡 �����Ƿ� �� �̻��� �ӵ��� ���ǹ��ϴ�.
		//���� �ӵ��� �ٿ����ϴµ�, (R-1)*2�� �ϸ� �ٽ� ���ڸ��� ���ƿ´�.
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
	int board[101][101];  //�� �ִٸ� �ش� ��� ��ȣ(0~M-1), ���ٸ� -1
	memset(board, -1, sizeof(board));

	int r, c, s, d, z;
	for (int i = 0; i < M; ++i) {
		cin >> r >> c >> s >> d >> z;
		sharks.push_back(shark(r, c, s, d, z));
		board[r][c] = i;
	}

	int sum = 0; //���� ������ ũ�� ��

	for (int i = 1; i <= C; ++i) {
		for (int j = 1; j <= R; ++j) {
			//j���� �� �����ϴ� ���
			if (board[j][i] != -1) {
				sum += sharks[board[j][i]].size;

				sharks[board[j][i]].exist = false;
				board[i][j] = -1;
				break;
			}
		}

		memset(board, -1, sizeof(board));
		//���� ��ġ ��ȭ �� board�� �̹� �����ϴ��� Ȯ��
		for (int s = 0; s < sharks.size(); ++s) {
			if (sharks[s].exist == false)
				continue;

			sharks[s].change();

			if (board[sharks[s].r][sharks[s].c] == -1)
				board[sharks[s].r][sharks[s].c] = s;
			else {
				//�̹� �����ϴ��ź��� ���ο� �� �� ũ�ٸ� 
				//���� �ϴ� ���� ��������ʴ� ���·� �����ϰ�
				//�ش� board�� ���ο� ����� ��ȣ�� �ִ´�.
				if (sharks[board[sharks[s].r][sharks[s].c]].size < sharks[s].size) {
					sharks[board[sharks[s].r][sharks[s].c]].exist = false;
					board[sharks[s].r][sharks[s].c] = s;
				}
				//���ο� �� �� �۴ٸ� ���ο� ���� ��������ʴ� ���·� ����
				else {
					sharks[s].exist = false;
				}
			}
		}
	}

	cout << sum << endl;

	return 0;
}