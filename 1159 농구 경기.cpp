#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;

	int alphabet[26] = { 0 };  //���ĺ� �� ������ �迭
	string tmp;
	bool play = false;  //�÷��� �������� �Ǻ�

	//N����ŭ �ݺ����� ���鼭 ���ڿ��� �Է¹ް�
	//���� ù ���� ���ĺ� �迭 ���� ���� ��Ű��
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		alphabet[tmp[0]-'a']++;
	}

	//���ĺ� ����(26) ��ŭ �ݺ����� ���鼭
	//5�� �̻��̶�� �ش� ���� ����ϱ�.
	for (int i = 0; i < 26; ++i) {
		if (alphabet[i] >= 5) {
			play = true;
			cout << char(i + 'a');
		}
	}

	//��⸦ �� �� ���
	if (play == false)
		cout << "PREDAJA" << endl;

	return 0;
}