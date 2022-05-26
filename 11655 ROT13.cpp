// https://www.acmicpc.net/problem/11655

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	string S;
	getline(cin, S);

	for (int i = 0; i < S.length(); ++i) {
		// 소문자인 경우
		if (S[i] >= 'a' && S[i] <= 'z') {
			if (S[i] + 13 > 'z') S[i] = S[i] + 13 - 26;
			else S[i] += 13;
		}
		else if (S[i] >= 'A' && S[i] <= 'Z') {
			if (S[i] + 13 > 'Z') S[i] = S[i] + 13 - 26;
			else S[i] += 13;
		}
	}

	cout << S << endl;

	return 0;
}