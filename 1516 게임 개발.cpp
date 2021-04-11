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

int N;
int cost[501] = { 0 };  //정점간의 관계를 표시할 그래프
int entryDegree[101] = { 0 }; //각 노드들의 진입 차수 개수 
bool visit[101];              //정점 방문 표시


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int a;

	for (int i = 1; i <= N; ++i) {
		cin >> cost[i];
		entryDegree[i]++;  //b의 진입차수 증가

		while (1) {
			cin >> a;

			if (a == -1)
				break;


		}
	}

	return 0;
}