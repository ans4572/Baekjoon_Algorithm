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

	//��ٸ� ����
	int a, b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		board[a] = b;
	}

	//�� ����
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		board[a] = b;
	}

	bool visit[101] = { false };   //�湮 ǥ��
	queue<pair<int, int> > q;      //first: num, second: �ֻ��� Ƚ��
	q.push(make_pair(1,0));
	visit[1] = true;
	int ans = 100;

	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();
		
		//100�� ������ ���
		if (now.first == 100) {
			ans = now.second;
			break;
		}
		//94 �̻��� ���� �ֻ��� �ѹ��� ������ ��.
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