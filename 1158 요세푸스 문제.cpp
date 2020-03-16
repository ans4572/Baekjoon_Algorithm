#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> Q;
	for (int i = 1; i <= N; ++i)
		Q.push(i);

	cout << "<";
	while (!Q.empty()) {
		if (Q.size() == 1) {
			cout << Q.front() << ">";
			return 0;
		}

		for (int i = 1; i < K; ++i) {
			Q.push(Q.front());
			Q.pop();
		}
		cout << Q.front() << ", ";
		Q.pop();
	}

	return 0;
}