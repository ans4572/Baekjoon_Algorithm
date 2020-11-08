#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

string s;

bool palindrome(string s) {
	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - 1 - i])
			return false;
	}

	return true;
}

bool similarPalindrome(int left, int right, bool skip)
{
	if (left > right)return true;
	if (s[left] == s[right])return similarPalindrome(left + 1, right - 1, skip);
	else if (skip) return max(similarPalindrome(left + 1, right, false), similarPalindrome(left, right - 1, false));
	else return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int ans;
	for (int i = 0; i < T; ++i) {
		cin >> s;

		if (palindrome(s)) ans = 0;
		else if (similarPalindrome(0,s.length()-1,1)) ans = 1;
		else ans = 2;

		cout << ans << endl;
	}

	return 0;
}