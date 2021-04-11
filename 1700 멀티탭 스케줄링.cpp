#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int command[101];        //����
int plug[101];        //�÷��׿� �����ִ� �� ����

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

		//�̹� �����ִ��� Ȯ��
		for (int j = 0; j < N; ++j) {
			if (plug[j] == command[i]) {
				isPlug = true;
				break;
			}
		}
		if (isPlug) continue;

		//�÷��װ� �����ִ� ���
		for (int j = 0; j < N; ++j) {
			if (plug[j] == 0) {
				plug[j] = command[i];
				isPlug = true;
				break;
			}
		}
		if (isPlug) continue;

		//�÷��װ� �������� �����ϴ� ���
		//���� �������� ���� ���߿� ������ ������ǰ ã�Ƽ� ����
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