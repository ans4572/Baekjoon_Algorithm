#include<iostream>
#include<vector>
#include<string>

using namespace std;

int top = -1; //���ÿ��� ���� top

void push(vector<char> &stack, char op)
{
	stack[++top] = op;
	return;
}

void pop(vector<char> &stack)
{
	//���� ������ top�� '('��� ���⸸�ϰ� ���X
	if (stack[top] == '(') {
		top--;
		return;
	}
	cout << stack[top--];
	return;
}

int main()
{
	//�Է� ���ڿ��� ������ ���� ����
	string input;
	cin >> input;

	vector<char> opStack(100); //���̰� �ִ� 100�̹Ƿ� �׸�ŭ �迭 ũ�� �Ҵ�

	//input �迭�� ���̸�ŭ �ݺ�
	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			//������ �켱������ ���� �����Ƿ� ������ top�� '('�� �����ϰ� �� pop���ְ� �� �� push
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
			//������ top�� ������ �켱������ �� ���ų� �����͵��̸� pop�ϰ� push
			while (top >= 0)
			{
				if (opStack[top] == '*' || opStack[top] == '/')
					pop(opStack);
				else
					break;
			}
			push(opStack, input[i]);
		}
		//'('�� ��� push�� ���ָ� �ȴ�.
		else if (input[i] == '(')
			push(opStack, input[i]);
		//'('�� ')'�� ó���ϴ� �������� ������ top���� �����ؼ� '('���������� pop�� ���ش�. 
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
		//�ǿ������� ��� �ٷ� ���
		else
			cout << input[i];
	}
	//���� ������ ���
	for (int i = top; i >= 0; --i)
		cout << opStack[i];

	return 0;
}