#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int N;
int arr[21][21];   //인구 수 저장 배열
int area[21][21];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void DFS(int r,int c, int value) {
	if (r < 1 || r > N || c < 1 || c > N) return;

	if (area[r][c] != 0) return;

	area[r][c] = value;
	for (int i = 0; i < 4; ++i)
		DFS(r + dx[i], c + dy[i], value);
}

int cal(int x, int y, int d1, int d2) {
	memset(area, 0, sizeof(area));

	int areaCount[6] = { 0,0,0,0,0,0 };

	//경계선을 5로 설정
	for (int i = 0; i <= d1; ++i) {
		area[x + i][y - i] = 5;
		area[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; ++i) {
		area[x + i][y + i] = 5;
		area[x + d1 + i][y - d1 + i] = 5;
	}

	//각 선거구 경계선 설정
	for (int r = x - 1; r > 0; --r)    
		area[r][y] = 1;
	for (int c = y + d2 + 1; c <= N; ++c) 
		area[x + d2][c] = 2;
	for (int c = y - d1 - 1; c > 0; --c) 
		area[x + d1][c] = 3;
	for (int r = x + d1 + d2 + 1; r <= N; ++r) 
		area[r][y - d1 + d2] = 4;

	//1,2,3,4 선거구 배정 
	DFS(1, 1, 1);
	DFS(1, N, 2);
	DFS(N, 1, 3);
	DFS(N, N, 4);

	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			areaCount[area[r][c]] += arr[r][c];
		}
	}

	areaCount[5] += areaCount[0];  //5선거구에 0선거구 더해주기

	int minCount = 40001;
	int maxCount = 0;

	for (int i = 1; i <= 5; ++i) {
		minCount = min(minCount, areaCount[i]);
		maxCount = max(maxCount, areaCount[i]);
	}

	return maxCount - minCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
	}

	int x, y, d1, d2;
	int ans = 40001;
	for (x = 1; x <= N - 2; ++x) {
		for (y = 2; y <= N - 1; ++y) {
			for (d1 = 1; d1 < y - 1; d1++) {
				for (d2 = 1; d2 < N - y; d2++) {
					if (x + d1 + d2 <= N) {
						ans = min(ans, cal(x, y, d1, d2));
					}
					else
						break;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}