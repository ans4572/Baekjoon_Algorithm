#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<long long> > graph(N + 1, vector<long long>(N + 1, 10000));

	int a, b;
	for (int i = 1; i <= M; ++i) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= N; ++i) {
		graph[i][i] = 0;
	}

	//�÷��̵� �ͼ� �˰��� ����
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}

	long long minP, minC = 10000;  //minP: ���� ���� ���, minC: ���� ���� �ɺ� �������� �� 
	long long sum = 0;
	for (int i = 1; i <= N; ++i) {
		sum = 0;
		for (int j = 1; j <= N; ++j) {
			sum += graph[i][j];
		}

		if (minC > sum) {
			minC = sum;
			minP = i;
		}
	}

	cout << minP << endl;

	return 0;
}