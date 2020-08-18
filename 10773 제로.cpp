#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
	int K,t;
	stack<int> s;
	cin >> K;
	
	for (int i = 0; i < K; ++i) {
		cin >> t;
		if (t == 0)
			s.pop();
		else
			s.push(t);
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << endl;

	return 0;
}