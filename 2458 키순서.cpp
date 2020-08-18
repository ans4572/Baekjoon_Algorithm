#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<bool> > student(N + 1, vector<bool>(N + 1, false));

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		student[a][b] = true;
	}

	//자기 자신 키는 아니까 true로 처리
	for (int i = 1; i <= N; ++i)
		student[i][i] = true;

	//플로이드 와샬 알고리즘 활용
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (student[i][k] == true && student[k][j] == true)
					student[i][j] = true;
			}
		}
	}

	//뒤집어서도 true를 채워준다.
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (student[i][j] == true)
				student[j][i] = true;
		}
	}

	//그래프 한 줄씩 반복문을 돌면서 전부 true라면 나머지 자기가 몇번째 키순서인지
	//알 수 있으므로 카운트를 더해준다.
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		bool isCount = true;
		for (int j = 1; j <= N; ++j) {
			if (student[i][j] == false) {
				isCount = false;
				break;
			}
		}
		if (isCount)
			ans++;
	}

	cout << ans << endl;

	return 0;
}