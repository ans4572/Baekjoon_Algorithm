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

bool dy[31][40001];   //dy[n][s]: 가능한 구슬 무게가 s 일때 n번째 추가 포함이 되었는지 여부
bool visit[40001];

//sum: 현재 index까지의 저울의 총 합
void solve(int index, int sum) {
	if (dy[index][sum] == true)
		return;

	dy[index][sum] = true;
	visit[sum] = true;

	if (index == N)
		return;
	
	solve(index + 1, sum + sinker[index]);          //왼쪽 저울에 올리기
	solve(index + 1, sum);                          //안 올리기
	solve(index + 1, abs(sum - sinker[index]));     //오른쪽 저울에 올리기
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