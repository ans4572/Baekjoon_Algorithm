#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	string input;
	cin >> input;

	int ans = 0;
	stack<int> s;
	vector<int> raiser;

	//�������� ���� ��ġ ã��
	for (int i = 0; i < input.length() - 1; ++i) {
		if (input[i] == '(' && input[i + 1] == ')')
			raiser.push_back(i);
	}

	int barCount = 0; //�ݺ����� �����鼭 ���� �����ϴ� �� ���� ����
	int index = 0; //raiser�迭 �ε���
	//�ݺ����� ���� ���� �������� ������ ���� bar������ŭ ans�� �����ش�.
	for (int i = 0; i < input.length(); ++i) {
		if (index < raiser.size() && i == raiser[index]) {
			ans += barCount;
			index++;
			i++;
		}
		else {
			if (input[i] == '(') {
				barCount++;
			}
			//���밡 �����Ƿ� ������ ������ ���̰� ans�� �ϳ� �����ش�.
			else {
				barCount--;
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}