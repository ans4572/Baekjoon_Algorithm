#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int p, s;
	int minPackage = 1000, minSingle = 1000;
	for (int i = 0; i < M; ++i) {
		cin >> p >> s;
		if (minPackage > p) minPackage = p;
		if (minSingle > s) minSingle = s;
	}
	
	//���� ��Ű�� �ּ� ������ (���� �ּ� ����*6)���� ũ�ų� ���� ���
	//��Ű���� �� �ʿ� ���� ������ ���� ��� ���� �ּҰ��̴�.
	if (minPackage >= minSingle * 6) 
		cout << N * minSingle << endl;
	else {
		int pNum = N / 6;  //package num
		int remain = N % 6;

		//(���� �ּ� ����*������)�� ��Ű�� �ּ� ���ݺ��� ������ ���
		if (minPackage >= minSingle * remain) 
			cout << pNum * minPackage + minSingle * remain << endl;
		//�ƴ϶�� ��Ű���� ��� ���� �� �����ϴ�.
		else {
			cout << (pNum + 1) * minPackage << endl;
		}
	}

	return 0;
}