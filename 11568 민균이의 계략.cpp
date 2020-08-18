#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, ans = 1;
	cin >> N;

	vector<int> card(N + 1);
	vector<int> dy(N + 1, 1);   //최대로 증가하는 수열 개수 저장
	for (int i = 1; i <= N; ++i)
		cin >> card[i];

	//LIS 알고리즘 사용
	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j > 0; --j) {
			if (card[i] > card[j]) { 
				dy[i] = max(dy[i], dy[j] + 1);  //더 큰 값으로 갱신
			}
		}

		//최대값 계산
		if (ans < dy[i])
			ans = dy[i];
	}

	cout << ans << endl;

	return 0;
}