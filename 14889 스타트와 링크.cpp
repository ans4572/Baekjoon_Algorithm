#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int N;
vector<vector<int> > arr;
int ans = 1000;
bool isStartTeam[20];   //true: ��ŸƮ�� / flase: ��ũ ��

//������ Ȱ���� DFS
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

		//���밪�� �� ���� ��� ����
		if (ans > abs(startTeam - linkTeam))
			ans = abs(startTeam - linkTeam);
	}
	else {
		//�ڸ��� ���� ��� �ش� index�� ������ ��ŸƮ������ �̱�
		if (count < N / 2) {
			isStartTeam[index] = true;
			DFS(count + 1, index + 1);
		}

		//�ش� index�� ������ ��ũ������ �̱�
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