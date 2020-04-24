#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

void DFS(int count, int num, vector<int> arr, vector<bool> visit) {
	visit[num] = true;
	if (count == N - 1) {
		for (int i = 0; i < N; ++i)
			printf("%d ",arr[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= N; ++i) {
			if (visit[i] == false) {
				arr[count + 1] = i;
				DFS(count + 1, i, arr, visit);
			}
		}
	}
	return;
}

int main() {
	cin >> N;

	vector<int> arr(N);
	vector<bool> visit(9, false);
	for (int i = 1; i <= N; ++i) {
		arr[0] = i;
		DFS(0, i, arr, visit);
	}

	return 0;
}