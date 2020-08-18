#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s = "";

	while (true) {
		getline(cin, s);

		if (s == ".")
			break;

		stack<char> stack;

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(' || s[i] == '[')
				stack.push(s[i]);
			else if (s[i] == ')') {
				if (stack.empty()) {
					stack.push('x');
					break;
				}
				if (stack.top() == '(') 
					stack.pop();
				else {
					stack.push('x');
					break;
				}
			}
			else if (s[i] == ']') {
				if (stack.empty()) {
					stack.push('x');
					break;
				}
				if (stack.top() == '[')
					stack.pop();
				else {
					stack.push('x');
					break;
				}
			}
		}

		if (!stack.empty())
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}

	return 0;
}