#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int arr[4];
char ops[4] = { '+','-','*','/' };
char useOp[3];      //���� ������ �����ڵ� 
int useOperand[4];  //���� ������ �ǿ����ڵ�
bool visit[4];      //������ ���� ���� �湮 ǥ��
bool possible = false;

double cal(double a, double b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else if (op == '/' && b != 0) return a / b;

	return -100;
}

bool isSatisfy() {
	if (cal(cal(useOperand[0], useOperand[1], useOp[0]), cal(useOperand[2], useOperand[3], useOp[2]), useOp[1]) == 24.0) return true;  // (A op B) op (C op D)
	if (cal(cal(cal(useOperand[0], useOperand[1], useOp[0]), useOperand[2], useOp[1]), useOperand[3], useOp[2]) == 24.0) return true;  // ((A op B) op C) op D
	if (cal(cal(useOperand[0], cal(useOperand[1], useOperand[2], useOp[1]), useOp[0]), useOperand[3], useOp[2]) == 24.0) return true;  // (A op (B op C)) op D
	if (cal(useOperand[0], cal(cal(useOperand[1], useOperand[2], useOp[1]), useOperand[3], useOp[2]), useOp[0]) == 24.0) return true;  // A op ((B op C) op D)
	if (cal(useOperand[0], cal(useOperand[1], cal(useOperand[2], useOperand[3], useOp[2]), useOp[1]), useOp[0]) == 24.0) return true;  // A op (B op (C op D))

	return false;
}

//������ Ȱ���Ͽ� �⺻ ���� �����
void makeExp(int index) {
	if (possible) return;  //�̹� 24�� ���� �� �ִ� ���

	if (index == 3) {
		//���� �� �Ŀ� �����ֱ�
		for (int i = 0; i < 4; ++i) {
			if (!visit[i])
				useOperand[index] = arr[i];
		}

		if (isSatisfy()) {
			cout << useOperand[0] << useOp[0] << useOperand[1] << useOp[1] << useOperand[2] << useOp[2] << useOperand[3] << endl;
			possible = true;
		}

		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (!visit[i]) {
			useOperand[index] = arr[i];

			visit[i] = true;
			for (int j = 0; j < 4; ++j) {
				useOp[index] = ops[j];
				makeExp(index + 1);
			}
			visit[i] = false;
		}
	}

	return;
}

int main() {
	int T;
	cin >> T;

	for (int test = 0; test < T; ++test) {
		possible = false;

		for (int i = 0; i < 4; ++i)
			cin >> arr[i];

		makeExp(0);

		if (possible) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}