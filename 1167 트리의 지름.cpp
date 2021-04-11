#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<pair<int, int> > node[100001];
bool visit[100001];
int maxNode, maxWeight = 0;

void DFS(int n, int w) {
	visit[n] = true;

	//����� ���� �� �湮 ���� ����� ����ġ�� w�� ������ �� maxWeight���� �� ū ����ġ�� �����Ѵٸ� ����
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
	int first, second, weight;
	for (int i = 1; i <= n; ++i) {
		cin >> first;

		cin >> second;
		while (second != -1) {
			cin >> weight;
			node[first].push_back(make_pair(second, weight));
			cin >> second;
		}
	}

	DFS(1, 0);     //ù��° DFS

	memset(visit, false, sizeof(visit));  //�ι�° DFS�� ���� �湮 �ٽ� �ʱ�ȭ
	maxWeight = 0;

	DFS(maxNode, 0);   //ù��° DFS���� ã�� maxNode���� Ž�� ����

	cout << maxWeight << endl;

	return 0;
}