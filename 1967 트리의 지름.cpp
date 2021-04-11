#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<pair<int,int> > node[10001];
bool visit[10001];
int maxNode, maxWeight = 0;

void DFS(int n, int w) {
	visit[n] = true;

	//연결된 노드들 중 방문 안한 노드의 가중치에 w를 더했을 때 maxWeight보다 더 큰 가중치가 존재한다면 갱신
	for (int i = 0; i < node[n].size(); ++i) {
		if (!visit[node[n][i].first]) {
			if (maxWeight < node[n][i].second + w) {
				maxWeight = node[n][i].second + w;
				maxNode = node[n][i].first;
			}

			DFS(node[n][i].first, node[n][i].second + w);
		}
	}
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	//input
	int parent, child, weight;
	for (int i = 0; i < n - 1; ++i) {
		cin >> parent >> child >> weight;
		node[parent].push_back(make_pair(child,weight));
		node[child].push_back(make_pair(parent, weight));
	}

	DFS(1, 0);     //첫번째 DFS

	memset(visit, false, sizeof(visit));  //두번째 DFS를 위해 방문 다시 초기화
	maxWeight = 0;

	DFS(maxNode, 0);   //첫번째 DFS에서 찾은 maxNode부터 탐색 시작
	
	cout << maxWeight << endl;

	return 0;
}