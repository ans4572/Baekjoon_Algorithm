#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int N, M;
deque<int> dq;

int minCount(int x) {
	int leftCount = 0, rightCount = 0;

	deque<int> temp = dq;
	//�������� ��� �� ĭ�� �̵���Ű�鼭 ã��
	while (temp.front() != x) {
		temp.push_back(temp.front());
		temp.pop_front();
		leftCount++;
	}

	temp = dq;
	//���������� ��� �� ĭ�� �̵���Ű�鼭 ã��
	while (temp.front() != x) {
		temp.push_front(temp.back());
		temp.pop_back();
		rightCount++;
	}

	//�� ���� count�� ������ dq ����
	if (leftCount < rightCount) {
		while (dq.front() != x) {
			dq.push_back(dq.front());
			dq.pop_front();
		}

		return leftCount;
	}
	else {
		while (dq.front() != x) {
			dq.push_front(dq.back());
			dq.pop_back();
		}

		return rightCount;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		dq.push_back(i);
	}

	int input, ans = 0;
	for (int i = 0; i < M; ++i) {
		cin >> input;

		if (dq.front() == input) {
			dq.pop_front();
		}
		else {
			ans += minCount(input);
			dq.pop_front();
		}
	}

	cout << ans << endl;

	return 0;
}