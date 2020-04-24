#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int miro[1001][1001];
int dy[1001][1001];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> miro[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dy[i][j] = miro[i][j] + max(dy[i - 1][j], max(dy[i][j - 1], dy[i - 1][j - 1]));
		}
	}

	cout << dy[N][M] << endl;

	return 0;
}