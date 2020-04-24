#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	int a, b;
	vector<vector<bool> > maps(N + 1, vector<bool>(N + 1, false));
	vector<bool> visit(N + 1, false); //방문 확인 배열
	vector<int> friends;              //상근이의 친구 저장 배열
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		maps[a][b] = true;
		maps[b][a] = true;
	}

	int count = 0; //초대할 사람 수
	
	//우선 상근이의 친구 저장 및 카운트 하는 반복문
	for (int i = 2; i <= N; ++i) {
		if (maps[1][i] == true) {
			count++;
			visit[i] = true;
			friends.push_back(i);
		}
	}

	//친구의 친구 카운트
	for (int i = 0; i < friends.size(); ++i) {
		for (int j = 2; j <= N; ++j) {
			if (visit[j] == false && maps[friends[i]][j] == true) {
				visit[j] = true;
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}