#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class person {
public:
	int parent = 0;

	person() {}
};

int main() {
	int N,P1,P2,M;
	cin >> N;
	cin >> P1 >> P2;
	cin >> M;

	vector<person> p(N+1);

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		p[b].parent = a;
	}

	vector<int> count(N + 1, 0);  //�̼� ����� ���� �迭
	vector<bool> visit(N + 1, false); //�湮 Ȯ�� �ؿ�
	queue<int> q;
	q.push(P1);
	visit[P1] = true;

	while (!q.empty()) {
		for (int i = 1; i <= N; ++i) {
			//�ݺ����� ���� q.front()�� �θ� or q.front()�� �θ��� ����� ã�´�.
			if ((visit[i] == false) && (p[i].parent == q.front() || i == p[q.front()].parent)) {
				visit[i] = true;
				count[i] = count[q.front()] + 1;
				q.push(i);
			}
		}
		q.pop();
	}

	if (count[P2] == 0) 
		cout << -1 << endl;
	else 
		cout << count[P2] << endl;

	return 0;
}