#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int H, W, N; //���� , ����, �մ� ��ȣ
	int room;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		//�մ� ��ȣ�� ���̺��� ���� ���� �ƴ� ��� ����
		if (H >= N) {
			room = N * 100 + 1;
		}
		else {
			//�� �տ� ���ڸ� ���Ҷ� N%H�� 0�̳� �ƴϳĿ� ���� ��츦 ���� 
			if (N % H == 0) {
				room = H * 100 + N / H;
			}
			else {
				room = (N % H) * 100 + (N / H) + 1;
			}
		}
		cout << room << endl;
	}
}