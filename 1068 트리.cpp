#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int N, deleteNode;
int node[51];
bool isDelete[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> node[i];
	}

	cin >> deleteNode;

	queue<int> q;
	q.push(deleteNode);
	isDelete[deleteNode] = true;
	
	//BFS를 활용하여 노드 삭제 진행
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < N; ++i) {
			if (node[i] == now) {   //해당 노드의 부모가 now인 경우 큐에 추가
				q.push(i);
				isDelete[i] = true;
			}
		}
	}

	//반복문을 돌면서 i번째 노드를 부모로 가지는 살아있는 노드가 존재하는지 확인하며 개수 파악
	int ans = 0;
	bool isLeaf = true;
	for (int i = 0; i < N; ++i) {
		isLeaf = true;

		if (isDelete[i])   //삭제된 노드인 경우
			continue;

		for (int j = 0; j < N; ++j) {
			if (node[j] == i && !isDelete[j]) {
				isLeaf = false;
				break;
			}
		}

		if (isLeaf) ans++;
	}

	cout << ans << endl;

	return 0;
}