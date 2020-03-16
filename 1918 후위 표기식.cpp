#include<iostream>
#include<vector>
#include<string>

using namespace std;

int top = -1; //스택에서 쓰일 top

void push(vector<char> &stack, char op)
{
	stack[++top] = op;
	return;
}

void pop(vector<char> &stack)
{
	//만약 스택의 top이 '('라면 빼기만하고 출력X
	if (stack[top] == '(') {
		top--;
		return;
	}
	cout << stack[top--];
	return;
}

int main()
{
	//입력 문자열과 연산자 스택 선언
	string input;
	cin >> input;

	vector<char> opStack(100); //길이가 최대 100이므로 그만큼 배열 크기 할당

	//input 배열의 길이만큼 반복
	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			//연산자 우선순위가 가장 낮으므로 스택의 top이 '('를 제외하고 다 pop해주고 그 후 push
			while (top >= 0)
			{
				if (opStack[top] == '(')
					break;
				else
					pop(opStack);
			}
			push(opStack, input[i]);
		}
		else if (input[i] == '*' || input[i] == '/')
		{
			//스택의 top이 연산자 우선순위가 더 높거나 같은것들이면 pop하고 push
			while (top >= 0)
			{
				if (opStack[top] == '*' || opStack[top] == '/')
					pop(opStack);
				else
					break;
			}
			push(opStack, input[i]);
		}
		//'('일 경우 push만 해주면 된다.
		else if (input[i] == '(')
			push(opStack, input[i]);
		//'('과 ')'를 처리하는 과정으로 스택의 top부터 시작해서 '('만날때까지 pop을 해준다. 
		else if (input[i] == ')')
		{
			int temp = top;
			while (opStack[temp] != '(')
			{
				pop(opStack);
				temp--;
			}
			pop(opStack);
		}
		//피연산자일 경우 바로 출력
		else
			cout << input[i];
	}
	//남은 연산자 출력
	for (int i = top; i >= 0; --i)
		cout << opStack[i];

	return 0;
}