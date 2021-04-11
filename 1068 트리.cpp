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
	
	//BFS�� Ȱ���Ͽ� ��� ���� ����
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < N; ++i) {
			if (node[i] == now) {   //�ش� ����� �θ� now�� ��� ť�� �߰�
				q.push(i);
				isDelete[i] = true;
			}
		}
	}

	//�ݺ����� ���鼭 i��° ��带 �θ�� ������ ����ִ� ��尡 �����ϴ��� Ȯ���ϸ� ���� �ľ�
	int ans = 0;
	bool isLeaf = true;
	for (int i = 0; i < N; ++i) {
		isLeaf = true;

		if (isDelete[i])   //������ ����� ���
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