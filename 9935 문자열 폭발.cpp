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

		// boom�� ������ ���ڿ� ���� ��� ���� Ȯ��
		if (input[i] == boom[boom.length() - 1] && s.size() >= boom.length()) {
			for (int j = boom.length() - 1 ; j >= 0; --j) {
				if (s.top() == boom[j]) {
					temp.push(s.top());
					s.pop();
				}
				//boom�� �ٸ� ���� �ִ� ��� ������� �ǵ����� �ݺ��� ����
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