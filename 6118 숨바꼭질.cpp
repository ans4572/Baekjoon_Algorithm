#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int N, M;
vector<int> graph[20001];
int shortest[20001];      //1�� �갣���κ��� �� ��帶�� �ִ� �Ÿ�
bool visit[20001];        //�湮 ǥ�� �迭

//���ͽ�Ʈ�� �˰��� Ȱ��
void dijkstra(int start) {
	queue<int> q;  //start���� ������ �� �ִ� ������� ť�� �־ Ȯ���ϰ� �ȴ�.
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
	shortest[1] = 0;  //1 to 1�� 0���� ����

	//����� �� �Է¹޾Ƽ� graph ����
	int a, b;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int hideNum = 0;     //����� �ϴ� �갣 ��ȣ
	int maxDistance = 0; //�ִ� �Ÿ�
	int maxCount = 1;    //���� �Ÿ��� ���� �갣 ��

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