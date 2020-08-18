#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, ans = 0;
bool graph[1001][1001];
bool visit[1001];  //방문 확인
queue<int> q;

void BFS(int num) {
	visit[num] = true;
	//연결된 것이 하나라도 있는지 판별
	for (int i = 1; i <= N; ++i) {
		if (graph[num][i] == true) {
			q.push(num);
			break;
		}
	}

	//만약 큐가 비어있다면 자기자신만 있는 것이므로 연결요소 증가시키기
	if (q.empty()) {
		ans++;
		return;
	}
	else {
		while (!q.empty()) {
			for (int i = 1; i <= N; ++i) {
				if (graph[q.front()][i] == true && visit[i] == false) {
					visit[i] = true;
					q.push(i);
				}
			}
			q.pop();
		}
		ans++;
		return;
	}
}

int main() {
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	for (int i = 1; i <= N; ++i) {
		if (visit[i] == true)
			continue;
		else {
			BFS(i);
		}
	}
	
	cout << ans << endl;

	return 0;
}