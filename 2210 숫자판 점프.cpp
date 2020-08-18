#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int arr[5][5];
int dh[4] = { 0,-1,0,+1 };
int dw[4] = { 1,0,-1,0 };

vector<string> num;

bool possible(int h, int w) {
	if (h >= 0 && h < 5 && w >= 0 && w < 5)
		return true;
	else
		return false;
}

void DFS(int count, int h, int w, string s) {
	if (count == 6) {
		for (int i = 0; i < num.size(); ++i) {
			if (s == num[i])
				return;
		}
		num.push_back(s);
	}
	else {
		for (int i = 0; i < 4; ++i) {
			if (possible(h + dh[i], w + dw[i])) {
				DFS(count + 1, h + dh[i], w + dw[i], s + to_string(arr[h][w]));
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			DFS(0, i, j, to_string(arr[i][j]));
		}
	}

	cout << num.size() << endl;

	return 0;
}