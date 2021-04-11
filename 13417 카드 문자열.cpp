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
			//현재 맨 앞의 문자가 다음 input[i]보다 크거나 같은 경우 input을 맨 앞에 삽입
			if (myWord.front() >= input[i]) 
				myWord.push_front(input[i]);
			//더 작은 경우는 맨 뒤로 삽입
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