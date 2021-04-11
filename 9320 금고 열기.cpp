#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int arr[4];
char ops[4] = { '+','-','*','/' };
char useOp[3];      //만든 수식의 연산자들 
int useOperand[4];  //만든 수식의 피연산자들
bool visit[4];      //순열을 위한 숫자 방문 표시
bool possible = false;

double cal(double a, double b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else if (op == '/' && b != 0) return a / b;

	return -100000;
}

bool isSatisfy() {
	if (fabs(cal(cal(useOperand[0], useOperand[1], useOp[0]), cal(useOperand[2], useOperand[3], useOp[2]), useOp[1]) - 24) < 0.001) return true;  // (A op B) op (C op D)
	if (fabs(cal(cal(cal(useOperand[0], useOperand[1], useOp[0]), useOperand[2], useOp[1]), useOperand[3], useOp[2]) - 24) < 0.001) return true;  // ((A op B) op C) op D
	if (fabs(cal(cal(useOperand[0], cal(useOperand[1], useOperand[2], useOp[1]), useOp[0]), useOperand[3], useOp[2]) - 24) < 0.001) return true;  // (A op (B op C)) op D
	if (fabs(cal(useOperand[0], cal(cal(useOperand[1], useOperand[2], useOp[1]), useOperand[3], useOp[2]), useOp[0]) - 24) < 0.001) return true;  // A op ((B op C) op D)
	if (fabs(cal(useOperand[0], cal(useOperand[1], cal(useOperand[2], useOperand[3], useOp[2]), useOp[1]), useOp[0]) - 24) < 0.001) return true;  // A op (B op (C op D))

	return false;
}

//순열을 활용하여 기본 수식 만들기
void makeExp(int index) {
	if (possible) return;  //이미 24를 만들 수 있는 경우

	if (index == 3) {
		//남은 수 식에 더해주기
		for (int i = 0; i < 4; ++i) {
			if (!visit[i])
				useOperand[index] = arr[i];
		}

		if (isSatisfy()) {
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
		memset(visit, false, sizeof(visit));
		possible = false;

		for (int i = 0; i < 4; ++i)
			scanf("%d", &arr[i]);

		makeExp(0);

		if (possible) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}