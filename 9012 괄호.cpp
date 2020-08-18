#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	int T;
	cin >> T;

	string input;
	for (int i = 0; i < T; ++i) {
		cin >> input;
		stack<char> s;
		bool end = false;
		for (int j = 0; j < input.length(); ++j) {
			if (input[j] == '(')
				s.push('('); 
			else {
				if (s.empty()) {
					cout << "NO" << endl;
					end = true;
					break;
				}
				else 
					s.pop();
			}
		}

		if(end) continue;

		if(s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}