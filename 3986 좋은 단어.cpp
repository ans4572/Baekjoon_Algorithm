// https://www.acmicpc.net/problem/3986

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>

using namespace std;

int main() {

	int N;
	cin >> N;

	int ans = 0;
	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;

		if (s.length() % 2 == 1)
			continue;

		stack<char> st;
		for (char a : s) {
			if (st.size() && st.top() == a) st.pop();
			else st.push(a);
		}

		// 스택이 비어있음 == 조건 만족
		if (st.empty()) ans++;
	}

	cout << ans << endl;

	return 0;
}