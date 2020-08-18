#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	//graph[a][b]���� a>b��� 1
	//a<b ��� 2
	//a==b ��� 3
	//�� �� ���ٸ� 100
	vector<vector<int> > graph(N + 1, vector<int>(N + 1, 100));
	
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 2;
	}

	for (int i = 1; i <= N; ++i)
		graph[i][i] = 3;

	//�÷��̵� �ͼ� �˰��� Ȱ��
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				//i�� j���� ū ��� ����
				if (graph[i][k] == 1 && graph[k][j] == 1) {
					graph[i][j] = 1;
					graph[j][i] = 2;
				}
			}
		}
	}

	//�� ����� �� �� ���� ������ ���� ���� ���
	int count;
	for (int i = 1; i <= N; ++i) {
		count = 0;
		for (int j = 1; j <= N; ++j) {
			if (graph[i][j] == 100)
				count++;
		}
		cout << count << endl;
	}

	return 0;
}