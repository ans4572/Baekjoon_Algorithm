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

	int left = 1;   //������ �ּ� �Ÿ�
	int right = home[N - 1] - home[0];  //������ �ִ� �Ÿ�
	int d, ans;    //d: �Ÿ�

	while (left <= right) {
		int mid = (left + right) / 2;

		int count = 1;  //mid�� ���� ������ ������ ������ �Ÿ��� �������� �� �������� ����, ù��° ���� �̹� �ϳ� �дٰ� ����
		int i = 0, jump = 0, diff;
		int start = home[0];

		//�����⸦ ��ġ�ϴ� �� �� ������ �Ÿ��� ��� mid���� ũ�ų� ���ƾ���.
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