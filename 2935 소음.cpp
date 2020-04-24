#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	string A,B;
	char op;
	cin >> A;
	cin >> op;
	cin >> B;

	//+�� ���
	if (op == '+') {
		//A�� B�� ���� ��� ù��° ���ڿ��� 2�� �ٲ��ش�.
		//ex) 100 + 100 = 200
		if (A == B) {
			A[0] = '2';
			cout << A << endl;
		}
		//A�� B�� �ٸ� ��� ���ڿ� ���̸� ���Ͽ� �� ���� ������ ���ڿ���
		//�� ū ������ ���ڿ����� �ش� �ε����� 1�� �ٲ��ش�.
		else {
			if (A.length() > B.length()) {
				A[A.length() - B.length()] = '1';
				cout << A << endl;
			}
			else {
				B[B.length() - A.length()] = '1';
				cout << B << endl;
			}
		}
	}
	//������ ���
	else if (op == '*') {
		//10�� �������� ������ A,B�� ������ ���� ���� ���̹Ƿ�
		//ex) 100 * 1000 = 10^2 * 10^3 = 10^5
		//���� ���̴� A�� ����(3) + B�� ����(4) - 1�� �� �� �̸� 0���� �� �ʱ�ȭ ���ش�.
		//ex) 100000�� ���̴� 3 + 4 - 1 =6
		vector<char> ans(A.length() + B.length() - 1,'0'); 
		ans[0] = '1';
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i];
	}

	return 0;
}