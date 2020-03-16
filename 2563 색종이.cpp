#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	bool board[100][100] = { false };  //board가 false라면 흰색, true라면 검정색
	int N, tx, ty;
	cin >> N;

	//색종이가 덮힌 곳이라면 true로 만들어준다.
	for (int i = 0; i < N; ++i) {
		cin >> tx >> ty;
		for (int x = tx; x < tx + 10; ++x) {
			for (int y = ty; y < ty + 10; ++y) {
				board[x][y] = true;
			}
		}
	}

	//true인 곳들의 총 개수를 구하면 그것이 넓이다.
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