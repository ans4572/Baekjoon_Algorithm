#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main() {
	int N;
	cin >> N;

	bool candidate[1000];   //000 ~ 999
	memset(candidate, true, sizeof(candidate));

	//세자리 수 숫자에서 겹치는 후보 제외
	for (int i = 123; i < 1000; ++i) {
		string s = to_string(i);
		if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) candidate[i] = false;
		if (s[0] == '0' || s[1] == '0' || s[2] == '0') candidate[i] = false;
	}
	
	string num;
	int strike, ball;
	string compare;      //123 ~ 1000
	int sCount, bCount;  //strike count, ball count

	for (int i = 0; i < N; ++i) {
		cin >> num >> strike >> ball;

		for (int j = 123; j < 1000; ++j) {
			sCount = 0;
			bCount = 0;
			if (candidate[j]) {
				compare = to_string(j);
				for (int x = 0; x < 3; ++x) {
					for (int y = 0; y < 3; ++y) {
						if (x == y && num[x] == compare[y])
							sCount++;
						if (x != y && num[x] == compare[y])
							bCount++;
					}
				}

				if (strike != sCount || ball != bCount)
					candidate[j] = false;
			}
		}
	}

	int ans = 0;
	for (int i = 123; i < 1000; ++i) {
		if (candidate[i])
			ans++;
	}

	cout << ans << endl;

	return 0;
}