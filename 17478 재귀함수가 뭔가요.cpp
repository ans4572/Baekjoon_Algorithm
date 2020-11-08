#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int N;

void recursion(int n) {
	if (n == N) {
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "\"����Լ��� ������?\"" << endl;
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "��� �亯�Ͽ���." << endl;
		return;
	}
	else {
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "\"����Լ��� ������?\"" << endl;
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
		recursion(n + 1);
		for (int i = 0; i < n; ++i) { cout << "____"; }
		cout << "��� �亯�Ͽ���." << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;

	recursion(0);

	return 0;
}