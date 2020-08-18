#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n;
	queue<int> q;
	cin >> n;

	for (int i = 1; i <= n; ++i) 
		q.push(i);
	
	while (q.size() > 1) {
		q.pop();
		if (q.size() == 1)
			break;
		q.push(q.front());
		q.pop();
	}

	cout << q.back() << endl;

	return 0;
}