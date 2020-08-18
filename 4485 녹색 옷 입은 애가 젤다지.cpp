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

//�ʱ�ȭ �Լ�
void init(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	memset(D, 200000, sizeof(D));
}

//���� ���� �����ϴ��� Ȯ���Ͽ� ��� ��ȯ �Լ�
bool possible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N)
		return true;
	else
		return false;
}

//���ͽ�Ʈ�� �˰���
void dijkstra(int start) {
	priority_queue<int, vector<int>, greater<int> > pq; //������������ �켱���� ť ����
	pq.push(start);

	int now, y, x;
	int nextY, nextX, nextNode;

	while (!pq.empty()) {
		now = pq.top();  //���� �� ���� ���� ��
		y = now / N;
		x = now % N;
		pq.pop();

		//4������ ���ʷ� �˻�
		for (int i = 0; i < 4; ++i) {
			nextY = y + dy[i];
			nextX = x + dx[i];
			nextNode = nextY * N + nextX;

			//���� ���� �ְ� ���� nextNode�� �ּҰ��� now�� �ּҰ�+nextNode�� �ݾ׺��� ū ���
			if (possible(nextY, nextX) && D[nextNode] > D[now] + map[nextY][nextX]) {
				D[nextNode] = D[now] + map[nextY][nextX];  //����
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