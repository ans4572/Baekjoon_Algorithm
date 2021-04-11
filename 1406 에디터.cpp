#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<char> dq;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); ++i) {
		dq.push_back(s[i]);
	}

	int M;
	cin >> M;

	int cursor = dq.size();
	char command, temp;

	for (int i = 0; i < M; ++i) {
		cin >> command;

		if (command == 'L') {
			if (cursor > 0) {
				dq.push_front(dq.back());
				dq.pop_back();
				cursor--;
			}
		}
		else if (command == 'D') {
			if (cursor < dq.size()) {
				dq.push_back(dq.front());
				dq.pop_front();
				cursor++;
			}
		}
		else if (command == 'B') {
			if (cursor > 0) {
				dq.pop_back();
				cursor--;
			}
		}
		else {
			cin >> temp;
			dq.push_back(temp);
			cursor++;
		}
	}

	//문자열 출력을 위해 커서를 맨 앞으로 이동
	while (cursor > 0) {
		dq.push_front(dq.back());
		dq.pop_back();
		cursor--;
	}

	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}

	return 0;
}