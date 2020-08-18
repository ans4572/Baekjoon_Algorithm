#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void cal(stack<double>& st, double a, double b, char op) {
	if (op == '+') st.push(a + b);
	else if (op == '-') st.push(a - b);
	else if (op == '*') st.push(a * b);
	else if (op == '/') st.push(a / b);

	return;
}

int main() {
	int N;
	cin >> N;

	string postfix;
	cin >> postfix;

	vector<int> operand(N);
	for (int i = 0; i < N; ++i) 
		cin >> operand[i];
	
	stack<double> st;
	for (int i = 0; i < postfix.length(); ++i) {
		double a, b;
		
		switch (postfix[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			cal(st, a, b, postfix[i]);
			break;
		default:
			st.push(operand[postfix[i] - 'A']);
			break;
		}
	}

	printf("%.2f", st.top());

	return 0;
}