#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;

int move(int x, int i) {
	if (i == 0)
		return x - 1;
	else if (i == 1)
		return x + 1;
	else
		return 2 * x;
}

int main() {
	vector<pair<int, bool>> visit(100001);  //pair_first: move num, pair_second: is visit 
	cin >> N >> K;

	//���� ��ġ�� �� ���� ���
	if (N > K) {
		cout << N - K << endl; //-1�� �ۿ� �� �����̹Ƿ� N - K��ŭ ���������Ѵ�. 
	}
	//���� ��ġ�� ���� ���
	else if (N == K) {
		cout << 0 << endl;
	}
	else {
		int x = N, moveX;
		queue<int> q;
		q.push(x);
		visit[x].first = 0;
		visit[x].second = true;
		while (1) {
			x = q.front();
			q.pop();
			for (int i = 0; i < 3; ++i) {
				moveX = move(x, i);
				if (moveX < 0 || moveX > 100000 || visit[moveX].second == true)
					continue;

				//���� ������ �� ������ �߰��ϴ� ���
				if (moveX == K) {
					cout << visit[x].first + 1 << endl;
					return 0;
				}
				if (visit[moveX].second == false) {
					visit[moveX].second = true;
					visit[moveX].first = visit[x].first + 1;
					q.push(moveX);
				}
			}
		}
	}

	return 0;
}