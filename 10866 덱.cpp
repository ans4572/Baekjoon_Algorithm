#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> dq;
	cin.ignore();
	string command;
	for (int i = 0; i < N; ++i) {
		getline(cin, command);

		if (command == "front") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}
		else if (command == "back") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}
		else if (command == "size") {
			cout << dq.size() << "\n";
		}
		else if (command == "empty") {
			if (dq.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (command == "pop_front") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else {
			//push_front
			if (command[5] == 'f') {
				int num = stoi(command.erase(0, 10));
				dq.push_front(num);
			}
			//push_back
			else {
				int num = stoi(command.erase(0, 9));
				dq.push_back(num);
			}
		}
	}

	return 0;
}