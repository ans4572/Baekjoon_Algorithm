#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

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
	cin >> N >> K;

	vector<pair<int, int> > visit(100001); //first: move num, second: visit num

	//처음부터 위치가 같거나 동생이 더 수가 작은 경우
	if (N >= K) {
		cout << N - K << endl;
		cout << 1 << endl;
		return 0;
	}

	queue<int> q;
	visit[N].first = 0;
	visit[N].second = 1;
	q.push(N);

	while (!q.empty()) {
		int nowX = q.front();

		q.pop();

		//이미 동생을 만나서 가장 빠른 시간이 정해졌고 nowX의 움직임 숫자가 이 수보다 크거나 같은 경우
		if (visit[K].first != 0 && visit[nowX].first >= visit[K].first) continue;

		for (int i = 0; i < 3; ++i) {
			int next = move(nowX, i);

			if (next < 0 || next > 100000) continue;  //범위를 벗어난 경우 

			//방문한 적이 없는 경우
			if (visit[next].second == 0) {
				visit[next].first = visit[nowX].first + 1;
				visit[next].second = visit[nowX].second;

				if(next != K) q.push(next);
			}
			else {
				//이미 방문한 적이 있고 next의 움직임 횟수가 nowX의 움직임 횟수 +1과 같은 경우
				if (visit[next].first == visit[nowX].first + 1) {
					visit[next].second += visit[nowX].second;    //방문 횟수만 증가
				}
			}
		}
	}

	cout << visit[K].first << endl;
	cout << visit[K].second << endl;

	return 0;
}