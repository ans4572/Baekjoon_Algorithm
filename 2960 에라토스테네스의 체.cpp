#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, K, count = 0, P, ans;
	cin >> N >> K;

	vector<bool> arr(N + 1);
	

	while (1) {
		//아직 지우지 않은 수 중 가장 작은 수 찾기
		for (int i = 2; i <= N; ++i) {
			if (arr[i] == false) {
				P = i;
				break;
			}
		}
		//아직 지우지 않은 P의 배수를 순서대로 지우기
		for (int i = P; i <= N; i += P) {
			if (arr[i] == false) {
				arr[i] = true;
				count++;
			}
			if (count == K) {
				ans = i;
				break;
			}
		}
		if (count == K)
			break;
	}

	cout << ans << endl;

	return 0;
}