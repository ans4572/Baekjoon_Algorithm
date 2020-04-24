#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	vector<int> coin(N);
	int dy[10001] = { 0 };   //dy[i]: 금액 i원을 만들 수 있는 경우의 수

	for (int i = 0; i < N; ++i) {
		cin >> coin[i];
	}

	/*
	각 동전에 대해 j원이 동전 i-1 개수만큼 사용해서
	만들 수 있는 경우의 수를 반복해서 구한다.
	ex) i = 0일때 coin[0]으로 만들 수 있는 경우의 수 구하고
	    i = 1일때 coin[0]과 coin[1]로 만들 수 있는 경우의 수 구한다.
		이를 i = N-1까지 반복
	*/
	dy[0] = 1;
	for (int i = 0; i < N ; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j >= coin[i])
				dy[j] += dy[j - coin[i]];
		}
	}

	cout << dy[K] << endl;

	return 0;
}