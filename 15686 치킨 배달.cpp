#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int N, M;
int map[51][51];
vector<pair<int, int>> chicken;   //치킨집 저장 배열
vector<pair<int, int>> home;      //집 저장 배열
int visit[14];                    //조합을 활용하여 방문 저장
int ans = INT_MAX;

void DFS(int count, int n) {
	if (count == M) {
		int sum = 0, dis;
		for (int i = 0; i < home.size(); ++i) {
			dis = INT_MAX;
			for (int j = 0; j < M; ++j) {
				dis = min(dis, 
					abs(home[i].first - chicken[visit[j]].first)
					+ abs(home[i].second - chicken[visit[j]].second));
			}
			sum += dis;
		}
		if (ans > sum)
			ans = sum;
	}
	else {
		for (int i = n; i < chicken.size(); ++i) {
			visit[count] = i;
			DFS(count + 1, i + 1);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) 
				home.push_back(make_pair(i, j));
			if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	DFS(0, 0);
	cout << ans << endl;

	return 0;
}