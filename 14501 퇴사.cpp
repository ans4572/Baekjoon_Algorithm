#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, ans = 0; 
vector<pair<int, int> > counsulting(16);

void DFS(int n, int sum) {
	if (n == N + 1) {
		if (ans < sum)
			ans = sum;
	}
	else {
		//n일의 상담을 진행하는 경우, (n + n일의 상담기간)이 조건은 N+1보다 작거나 같아야한다
		if (n + counsulting[n].first <= N + 1)
			DFS(n + counsulting[n].first, sum + counsulting[n].second);
		DFS(n + 1, sum); //n일의 상담을 진행하지 않는 경우
	}
	return;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> counsulting[i].first >> counsulting[i].second;

	DFS(1, 0);

	cout << ans << endl;

	return 0;
}