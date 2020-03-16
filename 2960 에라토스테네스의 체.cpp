#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, K, count = 0, P, ans;
	cin >> N >> K;

	vector<bool> arr(N + 1);
	

	while (1) {
		//���� ������ ���� �� �� ���� ���� �� ã��
		for (int i = 2; i <= N; ++i) {
			if (arr[i] == false) {
				P = i;
				break;
			}
		}
		//���� ������ ���� P�� ����� ������� �����
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