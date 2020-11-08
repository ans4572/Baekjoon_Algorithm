#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int N, K;

int move(int x, int i) {
	if (i == 0)
		return x - 1;
	else if (i == 1)
		return x + 1;
	else
		return 2 * x;
}

int main() {
	cin >> N >> K;

	vector<pair<int, int> > visit(100001); //first: move num, second: visit num

	//ó������ ��ġ�� ���ų� ������ �� ���� ���� ���
	if (N >= K) {
		cout << N - K << endl;
		cout << 1 << endl;
		return 0;
	}

	queue<int> q;
	visit[N].first = 0;
	visit[N].second = 1;
	q.push(N);

	while (!q.empty()) {
		int nowX = q.front();

		q.pop();

		//�̹� ������ ������ ���� ���� �ð��� �������� nowX�� ������ ���ڰ� �� ������ ũ�ų� ���� ���
		if (visit[K].first != 0 && visit[nowX].first >= visit[K].first) continue;

		for (int i = 0; i < 3; ++i) {
			int next = move(nowX, i);

			if (next < 0 || next > 100000) continue;  //������ ��� ��� 

			//�湮�� ���� ���� ���
			if (visit[next].second == 0) {
				visit[next].first = visit[nowX].first + 1;
				visit[next].second = visit[nowX].second;

				if(next != K) q.push(next);
			}
			else {
				//�̹� �湮�� ���� �ְ� next�� ������ Ƚ���� nowX�� ������ Ƚ�� +1�� ���� ���
				if (visit[next].first == visit[nowX].first + 1) {
					visit[next].second += visit[nowX].second;    //�湮 Ƚ���� ����
				}
			}
		}
	}

	cout << visit[K].first << endl;
	cout << visit[K].second << endl;

	return 0;
}