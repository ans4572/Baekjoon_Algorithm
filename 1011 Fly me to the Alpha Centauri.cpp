#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	long long x, y, dis, p;
	for (int i = 0; i < T; ++i) {
		p = 0;
		cin >> x >> y;
		dis = y - x;
		//3���ϴ� �� �Ÿ���ŭ �̵��Ѵ�.
		if (dis <= 3) {
			cout << dis << endl;
			continue;
		}
		
		
		//������(1,4,9,16..)�� ���� ��Ģ������ �ּ� �����̵��� 
		//�����ϹǷ� �̸� �������� �� p�� ���Ѵ�.
		//�Ÿ�:1 => 1, �Ÿ�:4 => 3, �Ÿ�:9 => 5, �Ÿ�:16 => 7 ...
		while (1) {
			if ((p + 1)*(p + 1) < dis)
				p++;
			else
				break;
		}

		//(p�� ���� + (p+1)�� ���� / 2)�� �ϸ� ���� ������ ���� ���� �ִ�.
		//���� �� ���ؿ� ���� �۰ų� ������ p*2�� ���̰�, ũ�ٸ� p*2+1�� ���̴�.
		if (dis <= (p*p + (p + 1)*(p + 1)) / 2)
			cout << p * 2 << endl;
		else
			cout << p * 2 + 1 << endl;
	}

	return 0;
}