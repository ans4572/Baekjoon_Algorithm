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

		//스택에 새로 넣는 stack[top]이 stack[top-1]보다 큰경우
		//stack[top-1]을 stack[top]으로 K이 0이 되거나 top이 0이 되거나 
		//stack[top-1]과 stack[top]이 같거나 큰수를 만날때까지 반복
		while (K > 0 && top > 0 && stack[top - 1] < stack[top]) {
			stack[top - 1] = stack[top];
			top--;
			K--;
		}
		top++;
	}

	//아직 K가 남아있다면 스택의 top부터 버린다
	while (K > 0) {
		top--;
		K--;
	}

	for (int i = 0; i < top; ++i) {
		cout << stack[i];
	}

	return 0;
}