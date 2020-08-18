#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int N;
int line[11];

int main() {
	cin >> N;

	//Ű�� 1�� ������� ������� ó��
	for (int i = 1; i <= N; ++i) {
		int left;
		cin >> left;

		//line 0������ �� ��ġ Ž��
		for (int j = 0; j < N; ++j) {
			//���ʿ� �� �̻� ū ���� ���� �ڸ��� ����ִ� ��� �ֱ�
			if (left == 0 && line[j] == 0) {
				line[j] = i;
				break;
			}
			//�ڸ��� ��������� ���ʿ� �� ū ���� �����ϴ� ��� �ǳʶپ����
			else if(line[j] == 0)
				left--;
		}
	}

	for (int i = 0; i < N; ++i)
		cout << line[i] << " ";
	
	return 0;
}