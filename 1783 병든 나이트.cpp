#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int N, M;

int dx[4] = { 1,2,2,1 };
int dy[4] = { 2,1,-1,-2 };

int main() {
	cin >> N >> M;

	int ans;

	//N�̳� M�� 1�̶�� �̵� �Ұ�
	if (N == 1 || M == 1)
		cout << 1 << endl;
	//N�� 2�� ���
	else if (N == 2) {
		if (M <= 8)
			cout << (M + 1) / 2;
		//M�� 9�̻��� ���
		else
			cout << 4 << endl;
	}
	//N�� 3�̻��� ���
	else {
		if (M <= 4)
			cout << M << endl;
		else if (M < 7)
			cout << 4 << endl;
		else if (M == 7)
			cout << 5 << endl;
		//�� ���� �� ����ϰ� �� �� �ִ밪�� 2ĭ ����, 1ĭ ������ / 2ĭ �Ʒ���, 1ĭ �������� �ݺ��ϴ� ���̴�.
		//���� 4���� �� ��� �� 5ĭ���� �ִ� (���� ���� - 7)��ŭ ĭ�� �� �湮�� �� �ִ�.
		else
			cout << 5 + (M - 7) << endl;
	}

	return 0;
}