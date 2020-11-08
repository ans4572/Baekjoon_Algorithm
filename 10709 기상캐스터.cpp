#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

char map[101][101];
int report[101][101];

int main() {
	int H, W;
	cin >> H >> W;

	memset(report, -1, sizeof(report));

	for (int h = 0; h < H; ++h){
		for (int w = 0; w < W; ++w) {
			cin >> map[h][w];
			if (map[h][w] == 'c') report[h][w] = 0;
		}
	}

	for (int h = 0; h < H; ++h) {
		for (int w = 1; w < W; ++w) {
			if (report[h][w - 1] != -1 && report[h][w] == -1) {
				report[h][w] = report[h][w - 1] + 1;
			}
		}
	}
	
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			cout << report[h][w] << " ";
		}
		cout << endl;
	}

	return 0;
}