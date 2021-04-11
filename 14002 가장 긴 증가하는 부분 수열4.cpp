#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<int> arr(N);
	vector<int> dy(1001, 1);

	for (int i = 0; i < N; ++i) 
		cin >> arr[i];
	
	// dy ����
	for (int i = 1; i < N; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (arr[i] > arr[j]) {
				dy[i] = max(dy[i], dy[j] + 1);
			}
		}
	}

	// ���� �� �����ϴ� �κ� ���� ���� ã��
	int maxIndex = 0;
	for (int i = 0; i < N; ++i) {
		if (dy[i] > dy[maxIndex]) 
			maxIndex = i;
	}
	
	// �����ϴ� ���� ã��
	int findNum = dy[maxIndex] - 1;
	stack<int> st;
	st.push(arr[maxIndex]);
	for (int i = maxIndex - 1; i >= 0; --i) {
		if (dy[i] == findNum && arr[i] < st.top()) {
			st.push(arr[i]);
			findNum--;
		}
	}

	cout << dy[maxIndex] << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}