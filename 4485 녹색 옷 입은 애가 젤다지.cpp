#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N;
int map[125][125];
int D[125 * 125];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//초기화 함수
void init(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	memset(D, 200000, sizeof(D));
}

//범위 내에 존재하는지 확인하여 결과 반환 함수
bool possible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N)
		return true;
	else
		return false;
}

//다익스트라 알고리즘
void dijkstra(int start) {
	priority_queue<int, vector<int>, greater<int> > pq; //오름차순으로 우선순위 큐 생성
	pq.push(start);

	int now, y, x;
	int nextY, nextX, nextNode;

	while (!pq.empty()) {
		now = pq.top();  //누적 합 가장 작은 수
		y = now / N;
		x = now % N;
		pq.pop();

		//4방향을 차례로 검색
		for (int i = 0; i < 4; ++i) {
			nextY = y + dy[i];
			nextX = x + dx[i];
			nextNode = nextY * N + nextX;

			//범위 내에 있고 현재 nextNode의 최소값이 now의 최소값+nextNode의 금액보다 큰 경우
			if (possible(nextY, nextX) && D[nextNode] > D[now] + map[nextY][nextX]) {
				D[nextNode] = D[now] + map[nextY][nextX];  //갱신
				pq.push(nextNode);
			}
		}
	}
}

int main() {
	int count = 1;

	while (true) {
		cin >> N;
		if (N == 0)
			break;
		init(N);

		D[0] = map[0][0];

		dijkstra(0);

		cout << "Problem " << count << ": " << D[N * N - 1] << endl;
		count++;
	}

	return 0;
}