#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

//방향: 0 => 위 , 1 => 오른쪽, 2 => 아래, 3 => 왼쪽
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	string s;
	for (int test = 0; test < T; ++test) {
		cin >> s;

		int x = 0, y = 0;
		int minX = 0, maxX = 0, minY = 0, maxY = 0;
		int dic = 0;        //방향: 0 => 위 , 1 => 오른쪽, 2 => 아래, 3 => 왼쪽
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == 'F') {
				x += dx[dic];
				y += dy[dic];
			}
			else if (s[i] == 'B') {
				x -= dx[dic];
				y -= dy[dic];
			}
			else if (s[i] == 'L') {
				dic = (dic + 3) % 4;
			}
			else {
				dic = (dic + 1) % 4;
			}

			minX = min(minX, x);
			maxX = max(maxX, x);
			minY = min(minY, y);
			maxY = max(maxY, y);
		}

		cout << abs(maxX - minX) * abs(maxY - minY) << endl;
	}

	return 0;
}