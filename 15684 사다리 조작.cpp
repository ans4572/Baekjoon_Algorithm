#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, H;
bool change[31][11];  //change[a][b]: a번째 가로줄과 b번째 세로줄에서 변화 발생
int ans = 4;          //답의 최대값은 3이므로 4로 초기화

//N개의 i번째 세로선의 결과가 전부 i번이 나오는지 확인
bool check() {
	for (int i = 1; i <= N; ++i) {
		int n = i, h = 1;
		while (h <= H) {
			if (change[h][n]) n++;
			else if (n > 1 && change[h][n - 1]) n--;

			h++;
		}

		//하나라도 다른 경우 false반환
		if (n != i) return false;
	}
	return true;
}

void DFS(int count, int n, int h) {
	if (count > 3) return;  //3을 넘는 경우 더이상 의미 x

	//마지막에 도달한 경우
	if (n == N) {
		if (check() && ans > count)
			ans = count;

		return;
	}
	else {
		int nextN = n, nextH = h + 1;
		if (h == H) {
			nextN = n + 1;
			nextH = 1;
		}

		if (!change[h][n]) {
			change[h][n] = true;
			DFS(count + 1, nextN, nextH);
			change[h][n] = false;
		}
		DFS(count, nextN, nextH);
	}
}

int main() {
	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		change[a][b] = true;
	}

	DFS(0, 1, 1);

	if (ans == 4) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}