#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main() {
	string arr;
	char board[15][15];
	memset(board, ' ', sizeof(board)); //board�� �� ��ĭ(' ')���� �ʱ�ȭ

	//string Ÿ������ ���ڿ��� �Է� ���� ��
	//borad�� ���ڷ� ����� �־��ش�.
	for (int i = 0; i < 5; ++i) {
		cin >> arr;
		for (int j = 0; j < arr.length(); ++j) {
			board[i][j] = arr[j];
		}
	}

	//�� board�� ���ξ� ���鼭 ��ĭ�� �ƴ϶�� ����Ѵ�.
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j][i] != ' ')
				cout << board[j][i];
		}
	}

	return 0;
}