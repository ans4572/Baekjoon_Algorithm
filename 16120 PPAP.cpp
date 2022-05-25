// https://www.acmicpc.net/problem/16120

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
#include<stack>

using namespace std;

int main() {
	
	string s;
	cin >> s;

	int pCount = 0;  // 이전에 나온 p 개수 저장용
	bool possible = true;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'A') {
			// ppap 조건에 맞는 경우
			// ppap -> p로 전환
			if (pCount >= 2 && i < s.length() - 1 && s[i + 1] == 'P') {
				pCount -= 1;
				i++;
			}
			else {
				possible = false;
				break;
			}
		}
		else
			pCount++;
	}

	// p는 오직 한개만 남아야함
	if (pCount == 1 && possible)
		cout << "PPAP" << endl;
	else
		cout << "NP" << endl;

	return 0;
}