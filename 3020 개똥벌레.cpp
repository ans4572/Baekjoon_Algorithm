#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, H;
	cin >> N >> H;

	//�� ���̺� ������ �������� ���� ����
	vector<int> bottom(H + 1,0); //����
	vector<int> top(H + 1,0);    //������

	int h;
	for (int i = 0; i < N / 2; ++i) {
		cin >> h;
		bottom[h]++;
		cin >> h;
		top[H - h + 1]++;  //h���̶�� �ؿ������� H-h+1 ���̺��� ����
	}

	//�κ��� ���ϱ�
	for (int i = 1; i < H; ++i) {
		top[i + 1] += top[i];
		bottom[H - i] += bottom[H - i + 1];
	}
	
	//���� 1���� H���� ���� ���� �ּҰ� ���ϱ�
	int sum, ans = 200001, ansCount = 0;
	for (int i = 1; i <= H; ++i) {
		sum = bottom[i] + top[i];
		if (ans == sum) 
			ansCount++;
		else if (ans > sum) {
			ans = sum;
			ansCount = 1;
		}
	}

	cout << ans << " " << ansCount << endl;

	return 0;
}