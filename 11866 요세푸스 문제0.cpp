#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	int K, N;
	cin >> K >> N;

	queue<int> q;
	for (int i = 1; i <= K; ++i) {
		q.push(i);
	}

	int count = 0;
	cout << "<";
	while (q.size() > 1) {
		count++;
		if (count == N) {
			cout << q.front() << ", ";
			q.pop();
			count = 0;
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}

	cout << q.front() << ">" << endl;

	return 0;
}