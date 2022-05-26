// https://www.acmicpc.net/problem/9996

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {

	int N;
	string s, pre, suf, input;
	
	cin >> N;
	cin >> s;

	int pos = s.find('*');
	pre = s.substr(0, pos);
	suf = s.substr(pos + 1);
	
	for (int i = 0; i < N; ++i) {
		cin >> input;
		if (pre.size() + suf.size() > input.size())
			cout << "NE\n";
		else {
			if (pre == input.substr(0, pre.size())
				&& suf == input.substr(input.size() - suf.size()))
				cout << "DA\n";
			else cout << "NE\n";
		}
	}

	return 0;
}