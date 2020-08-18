#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	int N,ans = 0;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		string word;
		stack<char> s;
		cin >> word;

		s.push(word[0]);
		for (int j = 1; j < word.length(); ++j) {
			if (!s.empty() && s.top() == word[j])
				s.pop();
			else
				s.push(word[j]);
		}

		if (s.empty())
			ans++;
	}

	cout << ans << endl;

	return 0;
}