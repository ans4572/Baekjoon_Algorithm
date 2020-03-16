#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//sqrt�� ��Ʈ, pow�� �ŵ�����
		double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (x1 == x2 && y1 == y2 && r1 != r2) {
			cout << 0 << endl;
		}
		//�� ���� ��ġ�� ��
		else if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		//�� ���� �����ϰų� ������ ��
		else if (pow(r1 + r2,2) == pow(d,2) || pow(r1 + d,2) == pow(r2,2) || pow(r2 + d,2) == pow(r1,2)) {
			cout << 1 << endl;
		}
		//�� ���� ���� ������ �ְ� ������ ���� ����
		//�� ���� �ٸ� ���� ���ο� �ְ� �� ���� ������ ���� ��
		else if (r1 + r2 < d || r1 + d < r2 || r2 + d < r1) {
			cout << 0 << endl;
		}
		//������
		else {
			cout << 2 << endl;
		}
	}

	return 0;
}