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

	vector<pair<int, int> > visit(100001);  //first: move num, second: prev

	//ó������ ��ġ�� ���� ���
	if (N == K) {
		cout << 0 << endl;
		cout << K << endl;
		return 0;
	}
	//�������� ���ڰ� ū ��� -1�θ� ã�� �� ����
	else if (N > K) {
		cout << N - K << endl;
		for (int i = N; i >= K; --i) {
			cout << i << " ";
		}
	}
	else {
		queue<int> q;
		visit[N].first = 0;
		visit[N].second = N;
		q.push(N);

		//BFSŽ��
		while (!q.empty()) {
			int nowX = q.front();

			q.pop();

			//������ �̹� �߰��� ��� �ݺ��� Ż��
			if (visit[K].first != 0)
				break;

			for (int i = 0; i < 3; ++i) {
				int next = move(nowX, i);

				if (next < 0 || next > 100000 || visit[next].first != 0 || next == N) continue;  //������ ����ų� �湮�� ���� ���� ���

				//���� �߰��� ���
				if (next == K) {
					visit[next].first = visit[nowX].first + 1;
					visit[next].second = nowX;
				}
				else {
					visit[next].first = visit[nowX].first + 1;
					visit[next].second = nowX;
					q.push(next);
				}
			}
		}

		cout << visit[K].first << endl;

		//K�� N�� �ɶ����� ���� ���� Ž��
		int t = K;
		vector<int> num;
		num.push_back(K);
		while (t != N) {
			t = visit[t].second;
			num.push_back(t);
		}

		for (int i = num.size() - 1; i >= 0; --i) {
			cout << num[i] << " ";
		}
	}

	return 0;
}