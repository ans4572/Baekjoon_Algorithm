#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	int pillar[501];   //±âµÕ ¹øÈ£
	int dy[501];

	for (int i = 0; i < 501; ++i) {
		pillar[i] = 0;
		dy[i] = 1;
	}

	int a, b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		pillar[a] = b;
	}

	int maxLine = 0;
	for (int i = 2; i < 501; ++i) {
		if (pillar[i] == 0) 
			continue;

		for (int j = i - 1; j >= 1; --j) {
			if (pillar[j] != 0 && pillar[i] > pillar[j]) 
				dy[i] = max(dy[i], dy[j] + 1);
		}

		if (maxLine < dy[i])
			maxLine = dy[i];
	}

	cout << N - maxLine << endl;

	return 0;
}