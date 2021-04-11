#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

long long arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	stack<int> st;
	while (true) {
		cin >> n;

		if (n == 0)
			break;
		
		long long left, right;
		long long ans = 0;

		for (int i = 0; i < n; ++i) 
			cin>>arr[i];
		
		for (int i = 0; i < n; ++i) {
			//top의 높이가 i번째 높이보다 큰 경우
			right = i;

			while (!st.empty() && arr[st.top()] > arr[i]) {
				long long height = arr[st.top()];
				st.pop();

				if (st.empty())
					left = 0;
				else
					left = st.top() + 1;

				long long width = right - left;

				if(ans < width * height)
					ans = width * height;
			}
			st.push(i);
		}

		//남은 스택 처리
		while (!st.empty()) {
			long long height = arr[st.top()];
			st.pop();

			long long width = n;

			if (!st.empty())
				width = n - st.top() - 1;

			if (ans < width * height)
				ans = width * height;
		}

		cout << ans << "\n";
	}

	return 0;
}