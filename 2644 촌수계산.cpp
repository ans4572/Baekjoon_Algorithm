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

	vector<int> count(N + 1, 0);  //촌수 계산을 위한 배열
	vector<bool> visit(N + 1, false); //방문 확인 해열
	queue<int> q;
	q.push(P1);
	visit[P1] = true;

	while (!q.empty()) {
		for (int i = 1; i <= N; ++i) {
			//반복문을 통해 q.front()의 부모 or q.front()가 부모인 사람을 찾는다.
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