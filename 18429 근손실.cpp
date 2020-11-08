#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int N, K, W = 500;
int kit[9];
bool visit[9];
int ans = 0;

void DFS(int day) {
	if (day == N) {
		//������ ������� ���� ŰƮ ã�Ƽ� ��� �Ǻ�
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && W + kit[i] - K >= 500) {
				ans++;
			}
		}
	}
	else {
		//��Ʈ��ŷ Ȱ��
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && W + kit[i] - K >= 500) {
				visit[i] = true;
				W += (kit[i] - K);
				DFS(day + 1); 

				visit[i] = false;
				W -= (kit[i] - K);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		cin >> kit[i];
	}

	DFS(1);

	cout << ans << endl;

	return 0;
}