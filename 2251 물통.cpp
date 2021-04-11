#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class State {
public:
	int A, B, C;  //남은 A,B,C의 물의 양

	State(int A, int B, int C) {
		this->A = A;
		this->B = B;
		this->C = C;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Avolumn, Bvolumn, Cvolumn;
	cin >> Avolumn >> Bvolumn >> Cvolumn;

	queue<State> q;
	bool visit[201][201][201] = { false };
	bool visitC[201] = { false };
	q.push(State(0, 0, Cvolumn));

	vector<int> ans;

	while (!q.empty()) {
		State now = q.front();
		q.pop();

		if (visit[now.A][now.B][now.C])
			continue;

		visit[now.A][now.B][now.C] = true;

		if (now.A == 0 && !visitC[now.C]) {
			ans.push_back(now.C);
			visitC[now.C] = true;
		}
		
		//A->B
		if (now.A + now.B > Bvolumn)
			q.push(State(now.A + now.B - Bvolumn, Bvolumn, now.C));
		else
			q.push(State(0, now.A + now.B, now.C));

		//A->C
		if (now.A + now.C > Cvolumn)
			q.push(State(now.A + now.C - Cvolumn, now.B, Cvolumn));
		else
			q.push(State(0, now.B, now.A + now.C));

		//B->A
		if (now.B + now.A> Avolumn)
			q.push(State(Avolumn, now.B + now.A - Avolumn, now.C));
		else
			q.push(State(now.A + now.B, 0, now.C));

		//B->C
		if (now.B + now.C > Cvolumn)
			q.push(State(now.A, now.B + now.C - Cvolumn, Cvolumn));
		else
			q.push(State(now.A, 0, now.B + now.C));

		//C->A
		if (now.C + now.A > Avolumn)
			q.push(State(Avolumn, now.B, now.C + now.A - Avolumn));
		else
			q.push(State(now.A + now.C, now.B, 0));

		//C->B
		if (now.C + now.B > Bvolumn)
			q.push(State(now.A, Bvolumn, now.C + now.B - Bvolumn));
		else
			q.push(State(now.A, now.B + now.C, 0));
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}

	return 0;
}