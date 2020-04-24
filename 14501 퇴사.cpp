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
		//n���� ����� �����ϴ� ���, (n + n���� ���Ⱓ)�� ������ N+1���� �۰ų� ���ƾ��Ѵ�
		if (n + counsulting[n].first <= N + 1)
			DFS(n + counsulting[n].first, sum + counsulting[n].second);
		DFS(n + 1, sum); //n���� ����� �������� �ʴ� ���
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