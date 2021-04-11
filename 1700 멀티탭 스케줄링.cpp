#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int command[101];        //순서
int plug[101];        //플러그에 꽂혀있는 것 저장

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, ans = 0;
	cin >> N >> K;

	for (int i = 0; i < K; ++i) {
		cin >> command[i];
	}

	int remain = 0;
	for (int i = 0; i < K; ++i) {
		bool isPlug = false;

		//이미 꽂혀있는지 확인
		for (int j = 0; j < N; ++j) {
			if (plug[j] == command[i]) {
				isPlug = true;
				break;
			}
		}
		if (isPlug) continue;

		//플러그가 남아있는 경우
		for (int j = 0; j < N; ++j) {
			if (plug[j] == 0) {
				plug[j] = command[i];
				isPlug = true;
				break;
			}
		}
		if (isPlug) continue;

		//플러그가 가득차서 빼야하는 경우
		//현재 시점에서 가장 나중에 나오는 전기제품 찾아서 빼기
		int maxAppear = 0, removeIndex = 0;
		bool isRemain = false;
		for (int j = 0; j < N; ++j) {
			isRemain = false;

			for (int k = i + 1; k < K; ++k) {
				if (plug[j] == command[k]) {
					isRemain = true;
					if (maxAppear < k) {
						maxAppear = k;
						removeIndex = j;
					}
					break;
				}
			}

			if (!isRemain) {
				removeIndex = j;
				break;
			}
		}

		plug[removeIndex] = command[i];
		ans++;
	}

	cout << ans << endl;

	return 0;
}