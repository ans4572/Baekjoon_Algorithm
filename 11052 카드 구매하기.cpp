#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[10001];  //dy[n]���� n��ŭ ī�� ������ �� 


int main() {
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> p(N + 1);           //ī�� �� ����
	
	for (int i = 1; i <= N; ++i) {
		cin >> p[i];
		dy[i] = p[1] * i;           //p1���θ� ī�� �����ϴ� ���� dy�� �� �ʱ�ȭ
	}

	//���� �˰��� �̿�
	//i = 2 ���� N���� ���鼭
	//dy[j-i]+p[i]�� ������ dy[j]�� ���Ͽ� �� ū ������ ����
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