#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N, M;
int arr[501];
int graph[501][501] = { 0 };  
int entryDegree[501] = { 0 }; //각 노드들의 진입 차수 개수 

//위상정렬
void topologySort() {
	int result[501];
	queue<int> q;

	//진입차수가 0인 정점 찾아서 큐에 삽입
	for (int i = 1; i <= N; ++i) {
		if (entryDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= N; ++i) {
		int x = q.front();
		q.pop();
		result[i] = x;

		//x와 연결된 간선을 모두 제거한다.
		for (int j = 1; j <= N; ++j) {
			if (graph[x][j] == 1) {
				graph[x][j] = 0;

				//만약 j의 진입차수를 하나 줄인 후 0이 되면 q에 넣는다.
				if (--entryDegree[j] == 0)
					q.push(j);
			}
		}
	}

	//결과 출력
	for (int i = 1; i <= N; ++i)
		cout << result[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		cin >> N;

		for (int i = 0; i < N; ++i)
			cin >> arr[i];

		cin >> M;

		int a, b;
		for (int i = 0; i < M; ++i) {
			cin >> a >> b;
			graph[a][b] = 1;
		}
	}

	return 0;
}