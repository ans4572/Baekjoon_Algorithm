#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	char board[8][8];

	int ans = 0;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'F' && (i + j) % 2 == 0)
				ans++;
		}
	}

	cout << ans << endl;

	return 0;
}