#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int board[101];

	for (int i = 1; i <= 100; ++i) {
		board[i] = i;
	}

	//사다리 배정
	int a, b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		board[a] = b;
	}

	//벰 배정
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		board[a] = b;
	}

	bool visit[101] = { false };   //방문 표시
	queue<pair<int, int> > q;      //first: num, second: 주사위 횟수
	q.push(make_pair(1,0));
	visit[1] = true;
	int ans = 100;

	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();
		
		//100에 도달한 경우
		if (now.first == 100) {
			ans = now.second;
			break;
		}
		//94 이상인 경우는 주사위 한번만 굴리면 됨.
		if (now.first >= 94) {
			ans = now.second + 1;
			break;
		}

		for (int i = 1; i <= 6; ++i) {
			if (!visit[now.first + i] && now.first + i <= 100) {
				visit[now.first + i] = true;
				if (board[now.first + i] == now.first + i) {
					q.push(make_pair(now.first + i,now.second+1));
				}
				else{
					q.push(make_pair(board[now.first + i], now.second + 1));
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}