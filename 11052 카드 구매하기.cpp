#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[10001];  //dy[n]에서 n만큼 카드 구매할 때 


int main() {
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> p(N + 1);           //카드 팩 가격
	
	for (int i = 1; i <= N; ++i) {
		cin >> p[i];
		dy[i] = p[1] * i;           //p1으로만 카드 구매하는 경우로 dy를 다 초기화
	}

	//냅색 알고리즘 이용
	//i = 2 부터 N까지 돌면서
	//dy[j-i]+p[i]와 기존의 dy[j]를 비교하여 더 큰 값으로 갱신
	for (int i = 2; i <= N; ++i) {
		for (int j = i; j <= N; ++j) {
			dy[j] = max(dy[j - i] + p[i], dy[j]);
		}
	}

	int max = 0;
	for (int i = 1; i <= N; ++i) {
		if (max < dy[i])
			max = dy[i];
	}

	cout << max << endl;

	return 0;
}