#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	bool board[100][100] = { false };  //board�� false��� ���, true��� ������
	int N, tx, ty;
	cin >> N;

	//�����̰� ���� ���̶�� true�� ������ش�.
	for (int i = 0; i < N; ++i) {
		cin >> tx >> ty;
		for (int x = tx; x < tx + 10; ++x) {
			for (int y = ty; y < ty + 10; ++y) {
				board[x][y] = true;
			}
		}
	}

	//true�� ������ �� ������ ���ϸ� �װ��� ���̴�.
	int count = 0;
	for (int x = 0; x < 100; ++x) {
		for (int y = 0; y < 100; ++y) {
			if (board[x][y] == true)
				count++;
		}
	}

	cout << count << endl;

	return 0;
}