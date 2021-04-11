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
int entryDegree[501] = { 0 }; //�� ������ ���� ���� ���� 

//��������
void topologySort() {
	int result[501];
	queue<int> q;

	//���������� 0�� ���� ã�Ƽ� ť�� ����
	for (int i = 1; i <= N; ++i) {
		if (entryDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= N; ++i) {
		int x = q.front();
		q.pop();
		result[i] = x;

		//x�� ����� ������ ��� �����Ѵ�.
		for (int j = 1; j <= N; ++j) {
			if (graph[x][j] == 1) {
				graph[x][j] = 0;

				//���� j�� ���������� �ϳ� ���� �� 0�� �Ǹ� q�� �ִ´�.
				if (--entryDegree[j] == 0)
					q.push(j);
			}
		}
	}

	//��� ���
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