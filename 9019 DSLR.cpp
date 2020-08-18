#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int main() {
	int T;
	cin >> T;

	int A, B;
	for (int test = 0; test < T; ++test) {
		bool visit[10000];
		memset(visit, false, sizeof(visit));
		cin >> A >> B;

		queue<pair<int, string> > q;
		q.push(make_pair(A, ""));

		while (!q.empty()) {
			pair<int, string> temp = q.front();
			q.pop();

			if (temp.first == B) {
				cout << temp.second << endl;
				break;
			}
			
			//��ɾ� D
			int num = (2 * temp.first) % 10000;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'D'));
			}

			//��ɾ� S
			num = (temp.first - 1) < 0 ? 9999 : temp.first - 1;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'S'));
			}

			//��ɾ� L
			num = (temp.first % 1000) * 10 + temp.first / 1000;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'L'));
			}

			//��ɾ� R
			num = (temp.first % 10) * 1000 + temp.first / 10;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'R'));
			}
		}
	}

	return 0;
}