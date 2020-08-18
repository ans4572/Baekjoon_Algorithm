#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, ans = 1;
	cin >> N;

	vector<int> card(N + 1);
	vector<int> dy(N + 1, 1);   //�ִ�� �����ϴ� ���� ���� ����
	for (int i = 1; i <= N; ++i)
		cin >> card[i];

	//LIS �˰��� ���
	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j > 0; --j) {
			if (card[i] > card[j]) { 
				dy[i] = max(dy[i], dy[j] + 1);  //�� ū ������ ����
			}
		}

		//�ִ밪 ���
		if (ans < dy[i])
			ans = dy[i];
	}

	cout << ans << endl;

	return 0;
}