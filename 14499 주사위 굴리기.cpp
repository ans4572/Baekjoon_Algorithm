#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int map[20][20];
int dice[7];  //주사위 위에 써 있는 수 1~6
int dx[5] = { 0,0,0,-1,+1 };
int dy[5] = { 0,+1,-1,0,0 };

void diceUp() {
	int temp = dice[6];
	dice[6] = dice[5];
	dice[5] = dice[1];
	dice[1] = dice[2];
	dice[2] = temp;
}

void diceDown() {
	int temp = dice[2];
	dice[2] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[6];
	dice[6] = temp;
}

void diceLeft() {
	int temp = dice[6];
	dice[6] = dice[3];
	dice[3] = dice[1];
	dice[1] = dice[4];
	dice[4] = temp;
}

void diceRight() {
	int temp = dice[4];
	dice[4] = dice[1];
	dice[1] = dice[3];
	dice[3] = dice[6];
	dice[6] = temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x, y, k;
	cin >> N >> M >> x >> y >> k;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	int command;   //1: 동쪽, 2: 서쪽, 3:북쪽, 4: 남쪽
	for (int i = 0; i < k; ++i) {
		cin >> command;

		//명령으로 인해 바깥으로 가는 경우 
		if (x + dx[command] < 0 || x + dx[command] >= N || y + dy[command] < 0 || y + dy[command] >= M)
			continue;

		x = x + dx[command];
		y = y + dy[command];

		if (command == 1) diceRight();
		else if (command == 2) diceLeft();
		else if (command == 3) diceUp();
		else diceDown();

		if (map[x][y] == 0) {
			map[x][y] = dice[1];
		}
		else {
			dice[1] = map[x][y];
			map[x][y] = 0;
		}

		cout << dice[6] << endl;
	}

	return 0;
}