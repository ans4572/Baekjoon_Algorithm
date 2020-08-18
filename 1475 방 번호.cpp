#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> count(10, 0);

	for (int i = 0; i < s.length(); ++i) {
		count[s[i] - '0']++;
	}

	//6�̳� 9�� ��� ���� ���Ͽ� 2�� ���� ���� �ʿ��� ��Ʈ�� ������ �ȴ�.
	//Ȧ���� ��츦 ����Ͽ� +1 �� ���ش�.
	count[6] = (count[6] + count[9] + 1) / 2;
	count[9] = count[6];

	//�ִ� �� ã��
	int maxNum = 0;
	for (int i = 0; i < 10; ++i) {
		if (count[maxNum] < count[i])
			maxNum = i;
	}

	cout << count[maxNum] << endl;

	return 0;
}