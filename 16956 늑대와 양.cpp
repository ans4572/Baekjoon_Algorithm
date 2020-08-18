#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C;
char pasture[501][501];        //'.':��ĭ, 'S':��, 'W':����
vector<pair<int, int> > wolf;  //������ ��ġ ����

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

bool inPasture(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> pasture[i][j];
			if (pasture[i][j] == 'W') {
				wolf.push_back(make_pair(i, j));
			}
		}
	}

	bool impossible = false;
	int nextR, nextC;

	//������ ��ġ �ϳ��� �ݺ����� ���鼭 ��Ÿ�� ġ��
	for (int i = 0; i < wolf.size(); ++i) {
		for (int j = 0; j < 4; ++j) {
			nextR = wolf[i].first + dr[j];
			nextC = wolf[i].second + dc[j];

			if (inPasture(nextR, nextC)) {
				if (pasture[nextR][nextC] == '.')
					pasture[nextR][nextC] = 'D';
				else if (pasture[nextR][nextC] == 'S') //���� ���� ���� ���� �ִ� ���
					impossible = true;                 //�Ұ���
			}
		}
	}

	if (impossible)
		cout << 0 << endl;
	else {
		cout << 1 << endl;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << pasture[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}