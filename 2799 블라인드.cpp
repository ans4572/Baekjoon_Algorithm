#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	vector<vector<char> > apartment(5 * M + 1, vector<char>(5 * N + 1));

	for (int i = 0; i < 5 * M + 1; ++i) {
		for (int j = 0; j < 5 * N + 1; ++j) {
			cin >> apartment[i][j];
		}
	}

	int windowCount[5] = { 0,0,0,0,0 };

	int h = 1, w = 1, starCount = 0;
	for (int i = 0; i < M * N; ++i) {
		starCount = 0;
		for (int j = 0; j < 4; ++j) {
			if (apartment[h + j][w] == '*')
				starCount++;
		}

		windowCount[starCount]++;

		w += 5;
		if (w > 5 * N) {
			w = 1;
			h += 5;
		}
	}

	for (int i = 0; i < 5; ++i) {
		cout << windowCount[i] << " ";
	}

	return 0;
}