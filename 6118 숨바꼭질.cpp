#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int N, M;
vector<int> graph[20001];
int shortest[20001];      //1번 헛간으로부터 각 노드마다 최단 거리
bool visit[20001];        //방문 표시 배열

//다익스트라 알고리즘 활용
void dijkstra(int start) {
	queue<int> q;  //start부터 도달할 수 있는 순서대로 큐에 넣어서 확인하게 된다.
	q.push(start);
	visit[start] = true;
	
	int now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); ++i) {
			if (!visit[graph[now][i]]) {
				shortest[graph[now][i]] = shortest[now] + 1;
				visit[graph[now][i]] = true;
				q.push(graph[now][i]);
			}
		}
	}
}

int main() {
	cin >> N >> M;

	memset(shortest, 20001, sizeof(shortest));
	shortest[1] = 0;  //1 to 1은 0으로 설정

	//연결된 길 입력받아서 graph 설정
	int a, b;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int hideNum = 0;     //숨어야 하는 헛간 번호
	int maxDistance = 0; //최대 거리
	int maxCount = 1;    //같은 거리를 갖는 헛간 수

	dijkstra(1);

	for (int i = 2; i <= N; ++i) {
		if (maxDistance < shortest[i]) {
			hideNum = i;
			maxDistance = shortest[i];
			maxCount = 1;
		}
		else if (maxDistance == shortest[i])
			maxCount++;
	}

	cout << hideNum << " " << maxDistance << " " << maxCount << endl;

	return 0;
}