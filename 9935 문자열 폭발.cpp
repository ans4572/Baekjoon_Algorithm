#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	string input, boom;
	cin >> input;
	cin >> boom;

	if (input.length() < boom.length()) {
		cout << input << endl;
		return 0;
	}

	stack<char> s;
	for (int i = 0; i < input.length(); ++i) {
		stack<char> temp;
		s.push(input[i]);

		// boom의 마지막 글자와 같은 경우 스택 확인
		if (input[i] == boom[boom.length() - 1] && s.size() >= boom.length()) {
			for (int j = boom.length() - 1 ; j >= 0; --j) {
				if (s.top() == boom[j]) {
					temp.push(s.top());
					s.pop();
				}
				//boom과 다른 것이 있는 경우 원래대로 되돌리고 반복문 종료
				else {
					while (!temp.empty()) {
						s.push(temp.top());
						temp.pop();
					}
					break;
				}
			}
		}
	}

	if (s.size() == 0)
		cout << "FRULA" << endl;
	else {
		string reverse = "";
		while (!s.empty()) {
			reverse += s.top();
			s.pop();
		}

		for (int i = reverse.length() - 1; i >= 0; --i) {
			cout << reverse[i];
		}
	}

	return 0;
}