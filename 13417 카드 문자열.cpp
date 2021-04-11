#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int main() {
	int T, N;
	cin >> T;

	for (int test = 0; test < T; ++test) {
		cin >> N;

		vector<char> input(N);
		deque<char> myWord;

		for (int i = 0; i < N; ++i) {
			cin >> input[i];
		}

		myWord.push_back(input[0]); 

		for (int i = 1; i < N; ++i) {
			//���� �� ���� ���ڰ� ���� input[i]���� ũ�ų� ���� ��� input�� �� �տ� ����
			if (myWord.front() >= input[i]) 
				myWord.push_front(input[i]);
			//�� ���� ���� �� �ڷ� ����
			else
				myWord.push_back(input[i]);
		}

		for (auto iter = myWord.begin(); iter != myWord.end(); ++iter) {
			cout << *iter;
		}
		cout << endl;
	}

	return 0;
}