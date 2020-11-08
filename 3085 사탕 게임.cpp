#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int N;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;
vector<vector<char> > arr;

int candy() {
	int result = 1;

	//세로 카운트
	for (int i = 0; i < N; ++i) {
		int count = 1;
		for (int j = 0; j < N - 1; ++j) {
			if (arr[i][j] == arr[i][j + 1]) count++;
			else {
				result = max(result, count);
				count = 1;
			}
		}
		result = max(result, count);
	}

	//가로 카운트
	for (int i = 0; i < N; ++i) {
		int count = 1;
		for (int j = 0; j < N - 1; ++j) {
			if (arr[j][i] == arr[j + 1][i]) count++;
			else {
				result = max(result, count);
				count = 1;
			}
		}
		result = max(result, count);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	arr.resize(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			//양 옆 스왑
			swap(arr[i][j], arr[i][j + 1]);
			ans = max(ans, candy());
			swap(arr[i][j], arr[i][j + 1]);  //다시 원래 위치로

			//위 아래 스왑
			swap(arr[j][i], arr[j + 1][i]);
			ans = max(ans, candy());
			swap(arr[j][i], arr[j + 1][i]);  //다시 원래 위치로
		}
	}

	cout << ans << endl;

	return 0;
}
