#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>

using namespace std;

int N, M;
int sinker[31];
int bead[8];

bool dy[31][40001];   //dy[n][s]: ������ ���� ���԰� s �϶� n��° �߰� ������ �Ǿ����� ����
bool visit[40001];

//sum: ���� index������ ������ �� ��
void solve(int index, int sum) {
	if (dy[index][sum] == true)
		return;

	dy[index][sum] = true;
	visit[sum] = true;

	if (index == N)
		return;
	
	solve(index + 1, sum + sinker[index]);          //���� ���￡ �ø���
	solve(index + 1, sum);                          //�� �ø���
	solve(index + 1, abs(sum - sinker[index]));     //������ ���￡ �ø���
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> sinker[i];

	solve(0, 0);

	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> bead[i];
	}

	for (int i = 0; i < M; ++i) {
		if (visit[bead[i]])
			cout << "Y ";
		else
			cout << "N ";
	}

	return 0;
}