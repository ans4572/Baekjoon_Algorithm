#include<iostream>
#include<string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int x = 665; //�ݺ������� x ������ �ϹǷ� 665�� ��
	for (int i = 0; i < N; i++) {
		x++;
		while (1) {
			string s = to_string(x); //x�� ���ڿ��� �ٲ㼭 ���ǹ��� ���
			bool find = false; //�ݺ��� 2���� ���������� ���� ���
			for (int j = 0; j < s.length() - 2; j++) {
				if (s[j] == '6' && s[j + 1] == '6' && s[j + 2] == '6') {
					find = true;
					break;
				}
			}
			if (find == true) {
				break;
			}
			x++;
		}
	}

	cout << x << endl;

	return 0;
}