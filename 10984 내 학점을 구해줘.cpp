#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int T, N;
	int C;
	double G;
	cin >> T;

	int C_sum;
	double G_sum;
	//���� ����� �ش� ���� * ���� /�� ���� ����
	//ex) (3���� * 4.0 + ... ) / 18����
	for (int i = 0; i < T; ++i) {
		C_sum = 0;
		G_sum = 0;
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> C >> G;
			C_sum += C;
			G_sum += G * C; 
		}

		cout << fixed;     //�Ҽ��� �Ʒ� ���� �����ϴ� ǥ��
		cout.precision(1); //�Ҽ��� �Ʒ��� 1�� ����

		cout << C_sum << " " << G_sum / C_sum << endl;
	}

	return 0;
}