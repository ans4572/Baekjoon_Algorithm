#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int> > board(N, vector<int>(4));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> board[i][j];
		}
	}



	return 0;
}