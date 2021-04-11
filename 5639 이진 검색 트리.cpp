#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int arr[10001];

void go(int l, int r) {
	if (l > r)
		return;

	int root = l;
	int start = l, end = r;
	while (arr[start] >= arr[root]) start++;
	while (arr[end] > arr[root]) end--;
	go(start, end);
	go(end + 1, r);
	cout << arr[root] << "\n";
}

int main() {
	int index = 0, input;

	while (cin>>input) {
		if (input == EOF) break;
		arr[index++] = input;
	}

	go(0, index - 1);

	return 0;
}