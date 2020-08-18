#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	//graph[a][b]에서 a>b라면 1
	//a<b 라면 2
	//a==b 라면 3
	//알 수 없다면 100
	vector<vector<int> > graph(N + 1, vector<int>(N + 1, 100));
	
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 2;
	}

	for (int i = 1; i <= N; ++i)
		graph[i][i] = 3;

	//플로이드 와샬 알고리즘 활용
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				//i가 j보다 큰 경우 갱신
				if (graph[i][k] == 1 && graph[k][j] == 1) {
					graph[i][j] = 1;
					graph[j][i] = 2;
				}
			}
		}
	}

	//비교 결과를 알 수 없는 물건의 개수 세서 출력
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