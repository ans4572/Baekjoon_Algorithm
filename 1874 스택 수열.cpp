#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int arr[100001];
bool visit[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int next = 1;
	stack<int> s;
	vector<char> result;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i) {
		//이미 pop한 수인 경우
		if (visit[arr[i]]) {
			cout << "NO" << endl;
			return 0;
		}

		//스택이 비어있거나 스택의 top이 input보다 작은 경우 push 진행
		if (s.empty() || s.top() < arr[i]) {
			for (int j = next; j <= arr[i]; ++j) {
				s.push(j);
				result.push_back('+');
			}
			
			next = arr[i] + 1;
			s.pop();
			visit[arr[i]] = true;
			result.push_back('-');
		}
		else if (s.top() == arr[i]) {
			s.pop();
			visit[arr[i]] = true;
			result.push_back('-');
		}
		else {
			while (!s.empty() && s.top() >= arr[i]) {
				visit[s.top()] = true;
				s.pop();
				result.push_back('-');
			}
		}
	}

	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << "\n";
	}

	return 0;
}