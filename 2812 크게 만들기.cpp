#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
char stack[500001];

int main() {
	cin >> N >> K;
	cin >> stack[0];

	int top = 1;
	for (int i = 1; i < N; ++i) {
		cin >> stack[top];

		//���ÿ� ���� �ִ� stack[top]�� stack[top-1]���� ū���
		//stack[top-1]�� stack[top]���� K�� 0�� �ǰų� top�� 0�� �ǰų� 
		//stack[top-1]�� stack[top]�� ���ų� ū���� ���������� �ݺ�
		while (K > 0 && top > 0 && stack[top - 1] < stack[top]) {
			stack[top - 1] = stack[top];
			top--;
			K--;
		}
		top++;
	}

	//���� K�� �����ִٸ� ������ top���� ������
	while (K > 0) {
		top--;
		K--;
	}

	for (int i = 0; i < top; ++i) {
		cout << stack[i];
	}

	return 0;
}