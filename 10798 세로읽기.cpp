#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main() {
	string arr;
	char board[15][15];
	memset(board, ' ', sizeof(board)); //board를 다 빈칸(' ')으로 초기화

	//string 타입으로 문자열을 입력 받은 후
	//borad에 문자로 나누어서 넣어준다.
	for (int i = 0; i < 5; ++i) {
		cin >> arr;
		for (int j = 0; j < arr.length(); ++j) {
			board[i][j] = arr[j];
		}
	}

	//각 board를 세로씩 돌면서 빈칸이 아니라면 출력한다.
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j][i] != ' ')
				cout << board[j][i];
		}
	}

	return 0;
}