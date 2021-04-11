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

	int N, K, ans = 0;
	cin >> N;
	cin >> K;

	if (K >= N) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> arr(N);     //�Է� ������ ��ġ
	vector<int> diff(N-1);  //�����鰣 ����
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());  //����

	for (int i = 0; i < N - 1; ++i) {
		diff[i] = arr[i + 1] - arr[i];
	}

	sort(diff.begin(), diff.end()); //����

	//(���߱� ���� - 1) ��ŭ ���� �� �Ÿ��� ���� ����
	for (int i = 0; i < N - 1 - (K-1); ++i) {
		ans += diff[i];
	}

	cout << ans << endl;

	return 0;
}