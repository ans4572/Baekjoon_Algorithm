#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;

	vector<int> home(N);
	for (int i = 0; i < N; ++i)
		cin >> home[i];

	sort(home.begin(), home.end());

	int left = 1;   //가능한 최소 거리
	int right = home[N - 1] - home[0];  //가능한 최대 거리
	int d, ans;    //d: 거리

	while (left <= right) {
		int mid = (left + right) / 2;

		int count = 1;  //mid를 가장 인접한 공유기 사이의 거리로 지정했을 때 공유기의 개수, 첫번째 집에 이미 하나 둔다고 가정
		int i = 0, jump = 0, diff;
		int start = home[0];

		//공유기를 설치하는 두 집 사이의 거리는 적어도 mid보다 크거나 같아야함.
		for (int i = 1; i < N; ++i) {
			d = home[i] - start;
			if (mid <= d) {
				count++;
				start = home[i];
			}
		}

		if (count < C) right = mid - 1;
		else if (count >= C) {
			ans = mid;
			left = mid + 1;
		}
	}

	cout << ans << endl;

	return 0;
}