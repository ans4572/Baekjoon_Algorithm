#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int N;
vector<vector<int> > arr;
int ans = 1000;
bool isStartTeam[20];   //true: 스타트팀 / flase: 링크 팀

//조합을 활용한 DFS
void DFS(int count, int index) {
	if (index == N) {
		if (count != N / 2) return;

		int startTeam = 0, linkTeam = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (isStartTeam[i] && isStartTeam[j]) startTeam += arr[i][j];
				if (!isStartTeam[i] && !isStartTeam[j]) linkTeam += arr[i][j];
			}
		}

		//절대값이 더 작은 경우 갱신
		if (ans > abs(startTeam - linkTeam))
			ans = abs(startTeam - linkTeam);
	}
	else {
		//자리가 남은 경우 해당 index의 선수를 스타트팀으로 뽑기
		if (count < N / 2) {
			isStartTeam[index] = true;
			DFS(count + 1, index + 1);
		}

		//해당 index의 선수를 링크팀으로 뽑기
		isStartTeam[index] = false;
		DFS(count, index + 1);
	}
}

int main() {
	cin >> N;

	arr.resize(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	DFS(0, 0);

	cout << ans << endl;

	return 0;
}