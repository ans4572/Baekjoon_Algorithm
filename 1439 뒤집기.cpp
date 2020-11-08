#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int zeroCount = 0, oneCount = 0; //0이 연속으로 나오는 개수, 1이 연속으로 나오는 개수
	if (s[0] == '0') zeroCount++;
	else oneCount++;

	for (int i = 1; i < s.length(); ++i) {
		if (s[i-1] != s[i]) {
			if (s[i] == '0') {
				zeroCount++;
			}
			else {
				oneCount++;
			}
		}
	}

	cout << min(zeroCount, oneCount) << endl;

	return 0;
}