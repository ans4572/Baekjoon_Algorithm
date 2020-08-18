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
			
			//명령어 D
			int num = (2 * temp.first) % 10000;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'D'));
			}

			//명령어 S
			num = (temp.first - 1) < 0 ? 9999 : temp.first - 1;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'S'));
			}

			//명령어 L
			num = (temp.first % 1000) * 10 + temp.first / 1000;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'L'));
			}

			//명령어 R
			num = (temp.first % 10) * 1000 + temp.first / 10;
			if (!visit[num]) {
				visit[num] = true;
				q.push(make_pair(num, temp.second + 'R'));
			}
		}
	}

	return 0;
}