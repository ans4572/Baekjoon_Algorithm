#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int N, K;
bool learn[26];
vector<string> words;
int ans = 0;

void go(int index, int learnCount) {
	//읽을 수 있는 단어 카운트
	if (learnCount == K - 5) {
		int count = 0;
		for (int i = 0; i < words.size(); ++i) {
			bool possible = true;
			for (int j = 0; j < words[i].length(); ++j) {
				if (learn[words[i][j] - 'a'] == false) {
					possible = false;
					break;
				}
			}
			if (possible)
				count++;
		}

		ans = max(ans, count);
	}

	for (int i = index; i < 26; ++i) {
		if (learn[i])
			continue;
		learn[i] = true;
		go(i + 1, learnCount + 1);
		learn[i] = false;
	}
	
	return;
}

int main() {
	cin >> N >> K;

	words.resize(N);

	for (int i = 0; i < N; ++i) {
		cin >> words[i];
	}

	//배울 수 있는 글자가 5개 미만이면 답은 항상 0
	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}
	//모든 단어를 배운 경우
	if (K == 26) {
		cout << N << endl;
		return 0;
	}

	//무조건 배워야하는 단어들
	learn['a' - 'a'] = true;
	learn['c' - 'a'] = true;
	learn['i' - 'a'] = true;
	learn['n' - 'a'] = true;
	learn['t' - 'a'] = true;

	go(0, 0);

	cout << ans << endl;

	return 0;
}