#include<iostream>

using namespace std;

//�Ҽ� �Ǻ� �Լ�
//j*j <= n �� �� ������ �Ҽ� �Ǻ��� �ϱ� ���� 2���� �� �� �������� ������ ������ ���� �ð� �ʰ��� �ȴ�. 
//�ð��� ���̴� ���� ������ ������δ� �� ���� �����ٱ����� ������ ���� ��.
//���� � �ڿ��� x�� sqrt(x)���� ū ���μ��� �����Ѵٸ�, x�� sqrt(x)�� ���� ���� 
//sqrt(x)���� �۾ƾ� �ϱ� ������, 2���� ���������� i�� ������Ű�� ���� �̹� �� ���� ��������� ���̱� ����
bool isPrime(int n) {
	bool prime = true;
	if (n != 1) {
		for (int j = 2; j*j <= n; j++) {
			if (n%j == 0) {
				prime = false;
				break;
			}
		}
		if (prime == true)
			return true;
	}
	return false;
}

int main()
{
	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			cout << i <<"\n";
		}
	}

	return 0;
}