#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, P;
	cin >> N >> P;

	stack<int> s[7];

	for (int i = 1; i <= 6; ++i)
		s[i].push(0);

	int ans = 0;
	int line, pret;
	for (int i = 0; i < N; ++i) {
		cin >> line >> pret;

		//해당 라인의 가장 큰 프렛이 새로운 프렛보다 작은 경우
		if (s[line].top() < pret) {
			s[line].push(pret);
			ans++;
		}
		//해당 라인의 가장 큰 프렛이 새로운 프렛보다 큰 경우
		else if (s[line].top() > pret) {
			//작거나 같을 때까지 pop진행
			while(s[line].top() > pret) {
				s[line].pop();
				ans++;
			}

			//더 작은 경우 새로 추가
			if (s[line].top() < pret) {
				s[line].push(pret);
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}