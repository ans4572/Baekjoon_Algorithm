#include<iostream>

using namespace std;

int fac(int n) {
	if (n == 0) //������ ���丮�� ������ 0~12�̹Ƿ� 0�� ����������! 
		return 1;
	else if (n == 1)
		return 1;
	else
		return n * fac(n - 1);
}

int main() {
	int N;
	cin >> N;
	cout << fac(N) << endl;

	return 0;
}