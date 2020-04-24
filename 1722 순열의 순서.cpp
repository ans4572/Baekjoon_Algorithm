#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long f[21]; //factorial

int main() {
	int N, choice;
	cin >> N;

	bool visit[21] = { false };  //����� ���� Ȯ��
	vector<int> per(N + 1, 0);

	//���丮�� �ʱ�ȭ
	f[0] = 1;
	for (int i = 1; i <= 20; ++i) {
		f[i] = f[i - 1] * i;
	}

	cin >> choice;

	if (choice == 1) {
		long long K;
		cin >> K;

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (visit[j] == true) //�̹� ����� ���ڶ�� �н�
					continue;
				//���� K�� f[N-i]���� ũ�ٸ� K�� �ٿ��ְ� �ݺ��� ��� ����
				if (K > f[N - i]) {
						K -= f[N - i];
				}
				//�۴ٸ� �ش� i��° ���ڴ� j�̰� �湮ǥ�� ���ش�.
				else {
					per[i] = j;
					visit[j] = true;
					break;
				}
			}
		}

		for (int i = 1; i <= N; ++i)
			cout << per[i] << " ";
		cout << endl;
	}
	else if (choice == 2) {
		long long count = 0;

		for (int i = 1; i <= N; ++i) {
			cin >> per[i];
		}

		for (int i = 1; i <= N; ++i) {
			//1���� ���鼭 per[i]���� ���� ���ڶ�� 
			//N-i��ŭ�� ���丮���� ���ϹǷν� skip�� �Ѵ�.
			//�Ŀ� �������ٸ� ����ߴٴ� ���� ǥ���ϰ� �ݺ����� �������´�.
			for (int j = 1; j <= N; ++j) {
				if (visit[j] == true)
					continue;
				if (j < per[i]) {
					count += f[N - i];
				}
				else {
					visit[j] = true;
					break;
				}
			}
		}
		cout << count + 1 << endl;
	}

	return 0;
}