#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int con = 0; //������ ���� ����
	for (int i = 1; i < N; i++) {
		int t = i; //i�� ����Ǹ� �ȵǹǷ� ���ο� ���� ����
		int sum = t;
		int d;
		//�� �ڸ������� �����ֱ�
		for (int j = 5; j >= 0; j--) {
			d = pow(10, j);
			sum += t / d;
			t %= d;
		}
		//�հ� N�� ���� �� ������ �����ϰ� break
		if (sum == N) {
			con = i;
			break;
		}
	}
	cout << con << endl;

	return 0;
}