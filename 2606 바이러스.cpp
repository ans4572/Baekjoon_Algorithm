#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, edge;   //N: computer num
	cin >> N;
	cin >> edge;

	vector<vector<bool> > com(N + 1, vector<bool>(N + 1));

	int a, b;
	for (int i = 0; i < edge; ++i) {
		cin >> a >> b;
		com[a][b] = true;
		com[b][a] = true;
	}

	//�÷��̵� �ͼ� �˰��� ����
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				//i�� j ������ k�� �� �� ����Ǿ� �ִٸ� i�� j�� ����Ǿ� ����.
				if (com[i][k] == true && com[k][j] == true)
					com[i][j] = true;
			}
		}
	}

	int count = 0;
	for (int i = 2; i <= N; ++i) {
		if (com[1][i] == true)
			count++;
	}
	
	cout << count << endl;

	return 0;
}