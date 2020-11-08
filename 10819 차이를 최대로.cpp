#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int N;
int arr[8];
bool visit[8];    //�湮 ǥ��
int index[8];     //����� �ε��� ���� ����
int ans = 0;

void cal(int n) {
	if (n == N) {
		int temp = 0;
		for (int i = 0; i < N - 1; ++i) {
			temp += abs(arr[index[i]] - arr[index[i + 1]]);
		}

		if (ans < temp) ans = temp;
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (!visit[i]) {
				visit[i] = true;
				index[n] = i;
				cal(n + 1);
				visit[i] = false;
			}
		}
	}

	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	cal(0);

	cout << ans << endl;

	return 0;
}