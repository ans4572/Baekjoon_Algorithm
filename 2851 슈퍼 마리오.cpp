#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int mushroom[10];
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		cin >> mushroom[i];
	}

	for (int i = 0; i < 10; ++i) {
		sum += mushroom[i];
		if (sum >= 100) {
			//������ ���� ���� 100�� �Ѱ�ٸ�
			//i ���������� �հ� i������ ���� ���� 100�� ���Ͽ�
			//�� ���� ������ ���Ͽ� ����Ѵ�.
			if ((100 - (sum - mushroom[i])) < sum - 100)
				cout << sum - mushroom[i] << endl;
			else
				cout << sum << endl;
			return 0;
		}
	}

	//100�� �� �ѱ� ���
	cout << sum << endl;

	return 0;
}