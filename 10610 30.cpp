#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string N;
	cin >> N;

	vector<char> num;
	for (int i = 0; i < N.length(); ++i)
		num.push_back(N[i]);

	sort(num.begin(), num.end(), greater<int>());

	//30�� ����� �Ǳ� ���ؼ��� ������ 2������ �ִ�
	//1. ���� �ڸ� ���ڴ� �ݵ�� 0�̿��� �Ѵ�.
	//2. ��� �ڸ� ������ ���� 3�� ����̿��� �Ѵ�.

	//��� �ڸ� ������ �� ���ϱ�
	int sum = 0;
	for (int i = 0; i < N.length(); ++i) {
		sum += (N[i] - '0');
	}

	//���� �ڸ��� 0������ sum�� 3�� ������� Ȯ��
	if (num[N.length() - 1] == '0' && (sum % 3 == 0)) {
		for (int i = 0; i < num.size(); ++i)
			cout << num[i];
	}
	else
		cout << -1 << endl;

	return 0;
}